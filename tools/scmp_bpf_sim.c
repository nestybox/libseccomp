/**
 * BPF Simulator
 *
 * Copyright (c) 2012 Red Hat <pmoore@redhat.com>
 * Author: Paul Moore <pmoore@redhat.com>
 */

/*
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of version 2.1 of the GNU Lesser General Public License as
 * published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, see <http://www.gnu.org/licenses>.
 */

#include <elf.h>
#include <errno.h>
#include <fcntl.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <linux/audit.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifndef _BSD_SOURCE
#define _BSD_SOURCE
#endif
#include <endian.h>

#include "bpf.h"

#if __i386__
#define ARCH_NATIVE		AUDIT_ARCH_X86
#elif __x86_64__
#ifdef __ILP32__
#define ARCH_NATIVE		AUDIT_ARCH_X86_64
#else
#define ARCH_NATIVE		AUDIT_ARCH_X86_64
#endif /* __ILP32__ */
#elif __arm__
#define ARCH_NATIVE		AUDIT_ARCH_ARM
#elif __MIPSEB__
#define ARCH_NATIVE		AUDIT_ARCH_MIPS
#elif __MIPSEL__
#define ARCH_NATIVE		AUDIT_ARCH_MIPSEL
#else
#error the simulator code needs to know about your machine type
#endif /* machine type guess */

#define BPF_PRG_MAX_LEN		4096

/**
 * BPF simulator machine state
 */
struct sim_state {
	uint32_t acc;
	uint32_t temp[BPF_SCRATCH_SIZE];
};

struct bpf_program {
	size_t i_cnt;
	bpf_instr_raw *i;
};

static unsigned int opt_verbose = 0;

/**
 * Convert a 16-bit target integer into the host's endianess
 * @param arch the architecture token
 * @param val the 16-bit integer
 *
 * Convert the endianess of the supplied value and return it to the caller.
 *
 */
uint16_t _ttoh16(uint32_t arch, uint16_t val)
{
	if (arch & __AUDIT_ARCH_LE)
		return le16toh(val);
	else
		return be16toh(val);
}

/**
 * Convert a 32-bit target integer into the host's endianess
 * @param arch the architecture token
 * @param val the 32-bit integer
 *
 * Convert the endianess of the supplied value and return it to the caller.
 *
 */
uint32_t _ttoh32(uint32_t arch, uint32_t val)
{
	if (arch & __AUDIT_ARCH_LE)
		return le32toh(val);
	else
		return be32toh(val);
}

/**
 * Convert a 32-bit host integer into the target's endianess
 * @param arch the architecture token
 * @param val the 32-bit integer
 *
 * Convert the endianess of the supplied value and return it to the caller.
 *
 */
uint32_t _htot32(uint32_t arch, uint32_t val)
{
	if (arch & __AUDIT_ARCH_LE)
		return htole32(val);
	else
		return htobe32(val);
}

/**
 * Print the usage information to stderr and exit
 * @param program the name of the current program being invoked
 *
 * Print the usage information and exit with EINVAL.
 *
 */
static void exit_usage(const char *program)
{
	fprintf(stderr,
		"usage: %s -f <bpf_file> [-v]"
		" -a <arch> -s <syscall_num> [-0 <a0>] ... [-5 <a5>]\n",
		program);
	exit(EINVAL);
}

/**
 * Handle a simulator fault
 * @param rc the error or return code
 *
 * Print a "FAULT" to stderr to indicate a simulator fault, and an errno value
 * if the simulator is running in verbose mode, then exit with EFAULT.
 *
 */
static void exit_fault(unsigned int rc)
{
	if (opt_verbose)
		fprintf(stderr, "FAULT: errno = %d\n", rc);
	else
		fprintf(stderr, "FAULT\n");
	exit(EFAULT);
}

/**
 * Handle a BPF program error
 * @param rc the error or return code
 * @param line the line number
 *
 * Print an "ERROR" to stderr to indicate a program error, and an errno value
 * if the simulator is running in verbose mode, then exit with ENOEXEC.
 *
 */
static void exit_error(unsigned int rc, unsigned int line)
{
	if (opt_verbose)
		fprintf(stderr, "ERROR: errno = %d, line = %d\n", rc, line);
	else
		fprintf(stderr, "ERROR\n");
	exit(ENOEXEC);
}

/**
 * Handle a simulator return/action
 * @param action the return value
 * @param line the line number
 *
 * Display the action to stdout and exit with 0.
 *
 */
static void end_action(uint32_t action, unsigned int line)
{
	uint32_t act = action & SECCOMP_RET_ACTION;
	uint32_t data = action & SECCOMP_RET_DATA;

	switch (act) {
	case SECCOMP_RET_KILL:
		fprintf(stdout, "KILL\n");
		break;
	case SECCOMP_RET_TRAP:
		fprintf(stdout, "TRAP\n");
		break;
	case SECCOMP_RET_ERRNO:
		fprintf(stdout, "ERRNO(%u)\n", data);
		break;
	case SECCOMP_RET_TRACE:
		fprintf(stdout, "TRACE(%u)\n", data);
		break;
	case SECCOMP_RET_ALLOW:
		fprintf(stdout, "ALLOW\n");
		break;
	default:
		exit_error(EDOM, line);
	}

	exit(0);
}

/**
 * Execute a BPF program
 * @param prg the loaded BPF program
 * @param sys_data the syscall record being tested
 *
 * Simulate the BPF program with the given syscall record.
 *
 */
static void bpf_execute(const struct bpf_program *prg,
			const struct seccomp_data *sys_data)
{
	unsigned int ip, ip_c;
	struct sim_state state;
	bpf_instr_raw *bpf;
	unsigned char *sys_data_b = (unsigned char *)sys_data;
	uint16_t code;
	uint8_t jt;
	uint8_t jf;
	uint32_t k;

	/* initialize the machine state */
	ip_c = 0;
	ip = 0;
	memset(&state, 0, sizeof(state));

	while (ip < prg->i_cnt) {
		/* get the instruction and bump the ip */
		ip_c = ip;
		bpf = &prg->i[ip++];

		code = _ttoh16(sys_data->arch, bpf->code);
		jt = bpf->jt;
		jf = bpf->jf;
		k = _ttoh32(sys_data->arch, bpf->k);

		switch (code) {
		case BPF_LD+BPF_W+BPF_ABS:
			if (bpf->k < BPF_SYSCALL_MAX) {
				uint32_t val = *((uint32_t *)&sys_data_b[k]);
				state.acc = _htot32(sys_data->arch, val);
			} else
				exit_error(ERANGE, ip_c);
			break;
		case BPF_ALU+BPF_OR+BPF_K:
			state.acc |= k;
			break;
		case BPF_ALU+BPF_AND+BPF_K:
			state.acc &= k;
			break;
		case BPF_JMP+BPF_JA:
			ip += k;
			break;
		case BPF_JMP+BPF_JEQ+BPF_K:
			if (state.acc == k)
				ip += jt;
			else
				ip += jf;
			break;
		case BPF_JMP+BPF_JGT+BPF_K:
			if (state.acc > k)
				ip += jt;
			else
				ip += jf;
			break;
		case BPF_JMP+BPF_JGE+BPF_K:
			if (state.acc >= k)
				ip += jt;
			else
				ip += jf;
			break;
		case BPF_RET+BPF_K:
			end_action(k, ip_c);
			break;
		default:
			/* since we don't support the full bpf language just
			 * yet, this could be either a fault or an error, we'll
			 * treat it as a fault until we provide full support */
			exit_fault(EOPNOTSUPP);
		}
	}

	/* if we've reached here there is a problem with the program */
	exit_error(ERANGE, ip_c);
}

/**
 * main
 */
int main(int argc, char *argv[])
{
	int opt;
	char *opt_file = NULL;
	FILE *file;
	size_t file_read_len;
	struct seccomp_data sys_data;
	struct bpf_program bpf_prg;

	/* initialize the syscall record */
	memset(&sys_data, 0, sizeof(sys_data));
	sys_data.arch = ARCH_NATIVE;

	/* parse the command line */
	while ((opt = getopt(argc, argv, "a:f:h:s:v0:1:2:3:4:5:")) > 0) {
		switch (opt) {
		case 'a':
			if (strcmp(optarg, "x86") == 0)
				sys_data.arch = AUDIT_ARCH_I386;
			else if (strcmp(optarg, "x86_64") == 0)
				sys_data.arch = AUDIT_ARCH_X86_64;
			else if (strcmp(optarg, "x32") == 0)
				sys_data.arch = AUDIT_ARCH_X86_64;
			else if (strcmp(optarg, "arm") == 0)
				sys_data.arch = AUDIT_ARCH_ARM;
			else if (strcmp(optarg, "mips") == 0)
				sys_data.arch = AUDIT_ARCH_MIPS;
			else if (strcmp(optarg, "mipsel") == 0)
				sys_data.arch = AUDIT_ARCH_MIPSEL;
			else
				exit_fault(EINVAL);
			break;
		case 'f':
			opt_file = strdup(optarg);
			if (opt_file == NULL)
				exit_fault(ENOMEM);
			break;
		case 's':
			sys_data.nr = strtol(optarg, NULL, 0);
			break;
		case 'v':
			opt_verbose = 1;
			break;
		case '0':
			sys_data.args[0] = strtoull(optarg, NULL, 0);
			break;
		case '1':
			sys_data.args[1] = strtoull(optarg, NULL, 0);
			break;
		case '2':
			sys_data.args[2] = strtoull(optarg, NULL, 0);
			break;
		case '3':
			sys_data.args[3] = strtoull(optarg, NULL, 0);
			break;
		case '4':
			sys_data.args[4] = strtoull(optarg, NULL, 0);
			break;
		case '5':
			sys_data.args[5] = strtoull(optarg, NULL, 0);
			break;
		case 'h':
		default:
			/* usage information */
			exit_usage(argv[0]);
		}
	}

	/* allocate space for the bpf program */
	/* XXX - we should make this dynamic */
	bpf_prg.i_cnt = 0;
	bpf_prg.i = calloc(BPF_PRG_MAX_LEN, sizeof(*bpf_prg.i));
	if (bpf_prg.i == NULL)
		exit_fault(ENOMEM);

	/* load the bpf program */
	file = fopen(opt_file, "r");
	if (file == NULL)
		exit_fault(errno);
	do {
		file_read_len = fread(&(bpf_prg.i[bpf_prg.i_cnt]),
				      sizeof(*bpf_prg.i), 1, file);
		if (file_read_len == 1)
			bpf_prg.i_cnt++;

		/* check the size */
		if (bpf_prg.i_cnt == BPF_PRG_MAX_LEN)
			exit_fault(E2BIG);
	} while (file_read_len > 0);
	fclose(file);

	/* execute the bpf program */
	bpf_execute(&bpf_prg, &sys_data);

	/* we should never reach here */
	exit_fault(EFAULT);
	return 0;
}