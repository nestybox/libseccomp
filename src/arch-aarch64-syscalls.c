/**
 * Enhanced Seccomp AArch64 Syscall Table
 *
 * Copyright (c) 2014 Red Hat <mjuszkiewicz@redhat.com>
 * Author: Marcin Juszkiewicz <mjuszkiewicz@redhat.com>
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

#include <string.h>

#include <seccomp.h>

#include "arch.h"
#include "arch-aarch64.h"

/* NOTE: based on Linux v5.4-rc4 */
const struct arch_syscall_def aarch64_syscall_table[] = { \
	{ "_llseek", __PNR__llseek },
	{ "_newselect", __PNR__newselect },
	{ "_sysctl", __PNR__sysctl },
	{ "accept", 202 },
	{ "accept4", 242 },
	{ "access", __PNR_access },
	{ "acct", 89 },
	{ "add_key", 217 },
	{ "adjtimex", 171 },
	{ "afs_syscall", __PNR_afs_syscall },
	{ "alarm", __PNR_alarm },
	{ "arm_fadvise64_64", __PNR_arm_fadvise64_64 },
	{ "arm_sync_file_range", __PNR_arm_sync_file_range },
	{ "arch_prctl", __PNR_arch_prctl },
	{ "bdflush", __PNR_bdflush },
	{ "bind", 200 },
	{ "bpf", 280 },
	{ "break", __PNR_break },
	{ "breakpoint", __PNR_breakpoint },
	{ "brk", 214 },
	{ "cachectl", __PNR_cachectl },
	{ "cacheflush", __PNR_cacheflush },
	{ "capget", 90 },
	{ "capset", 91 },
	{ "chdir", 49 },
	{ "chmod", __PNR_chmod },
	{ "chown", __PNR_chown },
	{ "chown32", __PNR_chown32 },
	{ "chroot", 51 },
	{ "clock_adjtime", 266 },
	{ "clock_adjtime64", __PNR_clock_adjtime64 },
	{ "clock_getres", 114 },
	{ "clock_getres_time64", __PNR_clock_getres_time64 },
	{ "clock_gettime", 113 },
	{ "clock_gettime64", __PNR_clock_gettime64 },
	{ "clock_nanosleep", 115 },
	{ "clock_nanosleep_time64", __PNR_clock_nanosleep_time64 },
	{ "clock_settime", 112 },
	{ "clock_settime64", __PNR_clock_settime64 },
	{ "clone", 220 },
	{ "clone3", __PNR_clone3 },
	{ "close", 57 },
	{ "close_range", 436 },
	{ "connect", 203 },
	{ "copy_file_range", 285 },
	{ "creat", __PNR_creat },
	{ "create_module", __PNR_create_module },
	{ "delete_module", 106 },
	{ "dup", 23 },
	{ "dup2", __PNR_dup2 },
	{ "dup3", 24 },
	{ "epoll_create", __PNR_epoll_create },
	{ "epoll_create1", 20 },
	{ "epoll_ctl", 21 },
	{ "epoll_ctl_old", __PNR_epoll_ctl_old },
	{ "epoll_pwait", 22 },
	{ "epoll_wait", __PNR_epoll_wait },
	{ "epoll_wait_old", __PNR_epoll_wait_old },
	{ "eventfd", __PNR_eventfd },
	{ "eventfd2", 19 },
	{ "execve", 221 },
	{ "execveat", 281 },
	{ "exit", 93 },
	{ "exit_group", 94 },
	{ "faccessat", 48 },
	{ "faccessat2", 439 },
	{ "fadvise64", 223 },
	{ "fadvise64_64", __PNR_fadvise64_64 },
	{ "fallocate", 47 },
	{ "fanotify_init", 262 },
	{ "fanotify_mark", 263 },
	{ "fchdir", 50 },
	{ "fchmod", 52 },
	{ "fchmodat", 53 },
	{ "fchown", 55 },
	{ "fchown32", __PNR_fchown32 },
	{ "fchownat", 54 },
	{ "fcntl", 25 },
	{ "fcntl64", __PNR_fcntl64 },
	{ "fdatasync", 83 },
	{ "fgetxattr", 10 },
	{ "finit_module", 273 },
	{ "flistxattr", 13 },
	{ "flock", 32 },
	{ "fork", __PNR_fork },
	{ "fremovexattr", 16 },
	{ "fsconfig", 431 },
	{ "fsetxattr", 7 },
	{ "fsmount", 432 },
	{ "fsopen", 430 },
	{ "fspick", 433 },
	{ "fstat", 80 },
	{ "fstat64", __PNR_fstat64 },
	{ "fstatat64", __PNR_fstatat64 },
	{ "fstatfs", 44 },
	{ "fstatfs64", __PNR_fstatfs64 },
	{ "fsync", 82 },
	{ "ftime", __PNR_ftime },
	{ "ftruncate", 46 },
	{ "ftruncate64", __PNR_ftruncate64 },
	{ "futex", 98 },
	{ "futex_time64", __PNR_futex_time64 },
	{ "futimesat", __PNR_futimesat },
	{ "get_kernel_syms", __PNR_get_kernel_syms },
	{ "get_mempolicy", 236 },
	{ "get_robust_list", 100 },
	{ "get_thread_area", __PNR_get_thread_area },
	{ "get_tls", __PNR_get_tls },
	{ "getcpu", 168 },
	{ "getcwd", 17 },
	{ "getdents", __PNR_getdents },
	{ "getdents64", 61 },
	{ "getegid", 177 },
	{ "getegid32", __PNR_getegid32 },
	{ "geteuid", 175 },
	{ "geteuid32", __PNR_geteuid32 },
	{ "getgid", 176 },
	{ "getgid32", __PNR_getgid32 },
	{ "getgroups", 158 },
	{ "getgroups32", __PNR_getgroups32 },
	{ "getitimer", 102 },
	{ "getpeername", 205 },
	{ "getpgid", 155 },
	{ "getpgrp", __PNR_getpgrp },
	{ "getpid", 172 },
	{ "getpmsg", __PNR_getpmsg },
	{ "getppid", 173 },
	{ "getpriority", 141 },
	{ "getrandom", 278 },
	{ "getresgid", 150 },
	{ "getresgid32", __PNR_getresgid32 },
	{ "getresuid", 148 },
	{ "getresuid32", __PNR_getresuid32 },
	{ "getrlimit", __PNR_getrlimit },
	{ "getrusage", 165 },
	{ "getsid", 156 },
	{ "getsockname", 204 },
	{ "getsockopt", 209 },
	{ "gettid", 178 },
	{ "gettimeofday", 169 },
	{ "getuid", 174 },
	{ "getuid32", __PNR_getuid32 },
	{ "getxattr", 8 },
	{ "gtty", __PNR_gtty },
	{ "idle", __PNR_idle },
	{ "init_module", 105 },
	{ "inotify_add_watch", 27 },
	{ "inotify_init", __PNR_inotify_init },
	{ "inotify_init1", 26 },
	{ "inotify_rm_watch", 28 },
	{ "io_cancel", 3 },
	{ "io_destroy", 1 },
	{ "io_getevents", 4 },
	{ "io_pgetevents", 292 },
	{ "io_pgetevents_time64", __PNR_io_pgetevents_time64 },
	{ "io_setup", 0 },
	{ "io_submit", 2 },
	{ "io_uring_setup", 425 },
	{ "io_uring_enter", 426 },
	{ "io_uring_register", 427 },
	{ "ioctl", 29 },
	{ "ioperm", __PNR_ioperm },
	{ "iopl", __PNR_iopl },
	{ "ioprio_get", 31 },
	{ "ioprio_set", 30 },
	{ "ipc", __PNR_ipc },
	{ "kcmp", 272 },
	{ "kexec_file_load", 294 },
	{ "kexec_load", 104 },
	{ "keyctl", 219 },
	{ "kill", 129 },
	{ "lchown", __PNR_lchown },
	{ "lchown32", __PNR_lchown32 },
	{ "lgetxattr", 9 },
	{ "link", __PNR_link },
	{ "linkat", 37 },
	{ "listen", 201 },
	{ "listxattr", 11 },
	{ "llistxattr", 12 },
	{ "lock", __PNR_lock },
	{ "lookup_dcookie", 18 },
	{ "lremovexattr", 15 },
	{ "lseek", 62 },
	{ "lsetxattr", 6 },
	{ "lstat", __PNR_lstat },
	{ "lstat64", __PNR_lstat64 },
	{ "madvise", 233 },
	{ "mbind", 235 },
	{ "membarrier", 283 },
	{ "memfd_create", 279 },
	{ "migrate_pages", 238 },
	{ "mincore", 232 },
	{ "mkdir", __PNR_mkdir },
	{ "mkdirat", 34 },
	{ "mknod", __PNR_mknod },
	{ "mknodat", 33 },
	{ "mlock", 228 },
	{ "mlock2", 284 },
	{ "mlockall", 230 },
	{ "mmap", 222 },
	{ "mmap2", __PNR_mmap2 },
	{ "modify_ldt", __PNR_modify_ldt },
	{ "mount", 40 },
	{ "move_mount", 429 },
	{ "move_pages", 239 },
	{ "mprotect", 226 },
	{ "mpx", __PNR_mpx },
	{ "mq_getsetattr", 185 },
	{ "mq_notify", 184 },
	{ "mq_open", 180 },
	{ "mq_timedreceive", 183 },
	{ "mq_timedreceive_time64", __PNR_mq_timedreceive_time64 },
	{ "mq_timedsend", 182 },
	{ "mq_timedsend_time64", __PNR_mq_timedsend_time64 },
	{ "mq_unlink", 181 },
	{ "mremap", 216 },
	{ "msgctl", 187 },
	{ "msgget", 186 },
	{ "msgrcv", 188 },
	{ "msgsnd", 189 },
	{ "msync", 227 },
	{ "multiplexer", __PNR_multiplexer },
	{ "munlock", 229 },
	{ "munlockall", 231 },
	{ "munmap", 215 },
	{ "name_to_handle_at", 264 },
	{ "nanosleep", 101 },
	{ "newfstatat", 79 },
	{ "nfsservctl", 42 },
	{ "nice", __PNR_nice },
	{ "oldfstat", __PNR_oldfstat },
	{ "oldlstat", __PNR_oldlstat },
	{ "oldolduname", __PNR_oldolduname },
	{ "oldstat", __PNR_oldstat },
	{ "olduname", __PNR_olduname },
	{ "oldwait4", __PNR_oldwait4 },
	{ "open", __PNR_open },
	{ "open_by_handle_at", 265 },
	{ "open_tree", 428 },
	{ "openat", 56 },
	{ "openat2", 437 },
	{ "pause", __PNR_pause },
	{ "pciconfig_iobase", __PNR_pciconfig_iobase },
	{ "pciconfig_read", __PNR_pciconfig_read },
	{ "pciconfig_write", __PNR_pciconfig_write },
	{ "perf_event_open", 241 },
	{ "personality", 92 },
	{ "pidfd_open", 434 },
	{ "pidfd_send_signal", 424 },
	{ "pipe", __PNR_pipe },
	{ "pipe2", 59 },
	{ "pivot_root", 41 },
	{ "pkey_alloc", 289 },
	{ "pkey_free", 290 },
	{ "pkey_mprotect", 288 },
	{ "poll", __PNR_poll },
	{ "ppoll", 73 },
	{ "ppoll_time64", __PNR_ppoll_time64 },
	{ "prctl", 167 },
	{ "pread64", 67 },
	{ "preadv", 69 },
	{ "preadv2", 286 },
	{ "prlimit64", 261 },
	{ "process_vm_readv", 270 },
	{ "process_vm_writev", 271 },
	{ "prof", __PNR_prof },
	{ "profil", __PNR_profil },
	{ "pselect6", 72 },
	{ "pselect6_time64", __PNR_pselect6_time64 },
	{ "ptrace", 117 },
	{ "putpmsg", __PNR_putpmsg },
	{ "pwrite64", 68 },
	{ "pwritev", 70 },
	{ "pwritev2", 287 },
	{ "query_module", __PNR_query_module },
	{ "quotactl", 60 },
	{ "read", 63 },
	{ "readahead", 213 },
	{ "readdir", __PNR_readdir },
	{ "readlink", __PNR_readlink },
	{ "readlinkat", 78 },
	{ "readv", 65 },
	{ "reboot", 142 },
	{ "recv", __PNR_recv },
	{ "recvfrom", 207 },
	{ "recvmmsg", 243 },
	{ "recvmmsg_time64", __PNR_recvmmsg_time64 },
	{ "recvmsg", 212 },
	{ "remap_file_pages", 234 },
	{ "removexattr", 14 },
	{ "rename", __PNR_rename },
	{ "renameat", 38 },
	{ "renameat2", 276 },
	{ "request_key", 218 },
	{ "restart_syscall", 128 },
	{ "rmdir", __PNR_rmdir },
	{ "rseq", 293 },
	{ "rt_sigaction", 134 },
	{ "rt_sigpending", 136 },
	{ "rt_sigprocmask", 135 },
	{ "rt_sigqueueinfo", 138 },
	{ "rt_sigreturn", 139 },
	{ "rt_sigsuspend", 133 },
	{ "rt_sigtimedwait", 137 },
	{ "rt_sigtimedwait_time64", __PNR_rt_sigtimedwait_time64 },
	{ "rt_tgsigqueueinfo", 240 },
	{ "rtas", __PNR_rtas },
	{ "s390_guarded_storage", __PNR_s390_guarded_storage },
	{ "s390_pci_mmio_read", __PNR_s390_pci_mmio_read },
	{ "s390_pci_mmio_write", __PNR_s390_pci_mmio_write },
	{ "s390_runtime_instr", __PNR_s390_runtime_instr },
	{ "s390_sthyi", __PNR_s390_sthyi },
	{ "sched_get_priority_max", 125 },
	{ "sched_get_priority_min", 126 },
	{ "sched_getaffinity", 123 },
	{ "sched_getattr", 275 },
	{ "sched_getparam", 121 },
	{ "sched_getscheduler", 120 },
	{ "sched_rr_get_interval", 127 },
	{ "sched_rr_get_interval_time64", __PNR_sched_rr_get_interval_time64 },
	{ "sched_setaffinity", 122 },
	{ "sched_setattr", 274 },
	{ "sched_setparam", 118 },
	{ "sched_setscheduler", 119 },
	{ "sched_yield", 124 },
	{ "seccomp", 277 },
	{ "security", __PNR_security },
	{ "select", __PNR_select },
	{ "semctl", 191 },
	{ "semget", 190 },
	{ "semop", 193 },
	{ "semtimedop", 192 },
	{ "semtimedop_time64", __PNR_semtimedop_time64 },
	{ "send", __PNR_send },
	{ "sendfile", 71 },
	{ "sendfile64", __PNR_sendfile64 },
	{ "sendmmsg", 269 },
	{ "sendmsg", 211 },
	{ "sendto", 206 },
	{ "set_mempolicy", 237 },
	{ "set_robust_list", 99 },
	{ "set_thread_area", __PNR_set_thread_area },
	{ "set_tid_address", 96 },
	{ "set_tls", __PNR_set_tls },
	{ "setdomainname", 162 },
	{ "setfsgid", 152 },
	{ "setfsgid32", __PNR_setfsgid32 },
	{ "setfsuid", 151 },
	{ "setfsuid32", __PNR_setfsuid32 },
	{ "setgid", 144 },
	{ "setgid32", __PNR_setgid32 },
	{ "setgroups", 159 },
	{ "setgroups32", __PNR_setgroups32 },
	{ "sethostname", 161 },
	{ "setitimer", 103 },
	{ "setns", 268 },
	{ "setpgid", 154 },
	{ "setpriority", 140 },
	{ "setregid", 143 },
	{ "setregid32", __PNR_setregid32 },
	{ "setresgid", 149 },
	{ "setresgid32", __PNR_setresgid32 },
	{ "setresuid", 147 },
	{ "setresuid32", __PNR_setresuid32 },
	{ "setreuid", 145 },
	{ "setreuid32", __PNR_setreuid32 },
	{ "setrlimit", __PNR_setrlimit },
	{ "setsid", 157 },
	{ "setsockopt", 208 },
	{ "settimeofday", 170 },
	{ "setuid", 146 },
	{ "setuid32", __PNR_setuid32 },
	{ "setxattr", 5 },
	{ "sgetmask", __PNR_sgetmask },
	{ "shmat", 196 },
	{ "shmctl", 195 },
	{ "shmdt", 197 },
	{ "shmget", 194 },
	{ "shutdown", 210 },
	{ "sigaction", __PNR_sigaction },
	{ "sigaltstack", 132 },
	{ "signal", __PNR_signal },
	{ "signalfd", __PNR_signalfd },
	{ "signalfd4", 74 },
	{ "sigpending", __PNR_sigpending },
	{ "sigprocmask", __PNR_sigprocmask },
	{ "sigreturn", __PNR_sigreturn },
	{ "sigsuspend", __PNR_sigsuspend },
	{ "socket", 198 },
	{ "socketcall", __PNR_socketcall },
	{ "socketpair", 199 },
	{ "splice", 76 },
	{ "spu_create", __PNR_spu_create },
	{ "spu_run", __PNR_spu_run },
	{ "ssetmask", __PNR_ssetmask },
	{ "stat", __PNR_stat },
	{ "stat64", __PNR_stat64 },
	{ "statfs", 43 },
	{ "statfs64", __PNR_statfs64 },
	{ "statx", 291 },
	{ "stime", __PNR_stime },
	{ "stty", __PNR_stty },
	{ "subpage_prot", __PNR_subpage_prot },
	{ "swapcontext", __PNR_swapcontext },
	{ "swapoff", 225 },
	{ "swapon", 224 },
	{ "switch_endian", __PNR_switch_endian },
	{ "symlink", __PNR_symlink },
	{ "symlinkat", 36 },
	{ "sync", 81 },
	{ "sync_file_range", 84 },
	{ "sync_file_range2", __PNR_sync_file_range2 },
	{ "syncfs", 267 },
	{ "syscall", __PNR_syscall },
	{ "sys_debug_setcontext", __PNR_sys_debug_setcontext },
	{ "sysfs", __PNR_sysfs },
	{ "sysinfo", 179 },
	{ "syslog", 116 },
	{ "sysmips", __PNR_sysmips },
	{ "tee", 77 },
	{ "tgkill", 131 },
	{ "time", __PNR_time },
	{ "timer_create", 107 },
	{ "timer_delete", 111 },
	{ "timer_getoverrun", 109 },
	{ "timer_gettime", 108 },
	{ "timer_gettime64", __PNR_timer_gettime64 },
	{ "timer_settime", 110 },
	{ "timer_settime64", __PNR_timer_settime64 },
	{ "timerfd", __PNR_timerfd },
	{ "timerfd_create", 85 },
	{ "timerfd_gettime", 87 },
	{ "timerfd_gettime64", __PNR_timerfd_gettime64 },
	{ "timerfd_settime", 86 },
	{ "timerfd_settime64", __PNR_timerfd_settime64 },
	{ "times", 153 },
	{ "tkill", 130 },
	{ "truncate", 45 },
	{ "truncate64", __PNR_truncate64 },
	{ "tuxcall", __PNR_tuxcall },
	{ "ugetrlimit", __PNR_ugetrlimit },
	{ "ulimit", __PNR_ulimit },
	{ "umask", 166 },
	{ "umount", __PNR_umount },
	{ "umount2", 39 },
	{ "uname", 160 },
	{ "unlink", __PNR_unlink },
	{ "unlinkat", 35 },
	{ "unshare", 97 },
	{ "uselib", __PNR_uselib },
	{ "userfaultfd", 282 },
	{ "usr26", __PNR_usr26 },
	{ "usr32", __PNR_usr32 },
	{ "ustat", __PNR_ustat },
	{ "utime", __PNR_utime },
	{ "utimensat", 88 },
	{ "utimensat_time64", __PNR_utimensat_time64 },
	{ "utimes", __PNR_utimes },
	{ "vfork", __PNR_vfork },
	{ "vhangup", 58 },
	{ "vm86", __PNR_vm86 },
	{ "vm86old", __PNR_vm86old },
	{ "vmsplice", 75 },
	{ "vserver", __PNR_vserver },
	{ "wait4", 260 },
	{ "waitid", 95 },
	{ "waitpid", __PNR_waitpid },
	{ "write", 64 },
	{ "writev", 66 },
	{ NULL, __NR_SCMP_ERROR },
};

/**
 * Resolve a syscall name to a number
 * @param name the syscall name
 *
 * Resolve the given syscall name to the syscall number using the syscall table.
 * Returns the syscall number on success, including negative pseudo syscall
 * numbers; returns __NR_SCMP_ERROR on failure.
 *
 */
int aarch64_syscall_resolve_name(const char *name)
{
	unsigned int iter;
	const struct arch_syscall_def *table = aarch64_syscall_table;

	/* XXX - plenty of room for future improvement here */
	for (iter = 0; table[iter].name != NULL; iter++) {
		if (strcmp(name, table[iter].name) == 0)
			return table[iter].num;
	}

	return __NR_SCMP_ERROR;
}

/**
 * Resolve a syscall number to a name
 * @param num the syscall number
 *
 * Resolve the given syscall number to the syscall name using the syscall table.
 * Returns a pointer to the syscall name string on success, including pseudo
 * syscall names; returns NULL on failure.
 *
 */
const char *aarch64_syscall_resolve_num(int num)
{
	unsigned int iter;
	const struct arch_syscall_def *table = aarch64_syscall_table;

	/* XXX - plenty of room for future improvement here */
	for (iter = 0; table[iter].num != __NR_SCMP_ERROR; iter++) {
		if (num == table[iter].num)
			return table[iter].name;
	}

	return NULL;
}


/**
 * Iterate through the syscall table and return the syscall mapping
 * @param spot the offset into the syscall table
 *
 * Return the syscall mapping at position @spot or NULL on failure.  This
 * function should only ever be used internally by libseccomp.
 *
 */
const struct arch_syscall_def *aarch64_syscall_iterate(unsigned int spot)
{
	/* XXX - no safety checks here */
	return &aarch64_syscall_table[spot];
}
