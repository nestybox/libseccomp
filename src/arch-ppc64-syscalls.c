/**
 * Enhanced Seccomp PPC64 Specific Code
 *
 * Copyright (c) 2014 Red Hat <pmoore@redhat.com>
 * Author: Paul Moore <paul@paul-moore.com>
 *
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
#include "arch-ppc64.h"

/* NOTE: based on Linux v5.4-rc4 */
const struct arch_syscall_def ppc64_syscall_table[] = { \
	{ "_llseek", 140 },
	{ "_newselect", 142 },
	{ "_sysctl", 149 },
	{ "accept", 330 },
	{ "accept4", 344 },
	{ "access", 33 },
	{ "acct", 51 },
	{ "add_key", 269 },
	{ "adjtimex", 124 },
	{ "afs_syscall", 137 },
	{ "alarm", 27 },
	{ "arm_fadvise64_64", __PNR_arm_fadvise64_64 },
	{ "arm_sync_file_range", __PNR_arm_sync_file_range },
	{ "arch_prctl", __PNR_arch_prctl },
	{ "bdflush", 134 },
	{ "bind", 327 },
	{ "bpf", 361 },
	{ "break", 17 },
	{ "breakpoint", __PNR_breakpoint },
	{ "brk", 45 },
	{ "cachectl", __PNR_cachectl },
	{ "cacheflush", __PNR_cacheflush },
	{ "capget", 183 },
	{ "capset", 184 },
	{ "chdir", 12 },
	{ "chmod", 15 },
	{ "chown", 181 },
	{ "chown32", __PNR_chown32 },
	{ "chroot", 61 },
	{ "clock_adjtime", 347 },
	{ "clock_adjtime64", __PNR_clock_adjtime64 },
	{ "clock_getres", 247 },
	{ "clock_getres_time64", __PNR_clock_getres_time64 },
	{ "clock_gettime", 246 },
	{ "clock_gettime64", __PNR_clock_gettime64 },
	{ "clock_nanosleep", 248 },
	{ "clock_nanosleep_time64", __PNR_clock_nanosleep_time64 },
	{ "clock_settime", 245 },
	{ "clock_settime64", __PNR_clock_settime64 },
	{ "clone", 120 },
	{ "clone3", 435 },
	{ "close", 6 },
	{ "close_range", 436 },
	{ "connect", 328 },
	{ "copy_file_range", 379 },
	{ "creat", 8 },
	{ "create_module", 127 },
	{ "delete_module", 129 },
	{ "dup", 41 },
	{ "dup2", 63 },
	{ "dup3", 316 },
	{ "epoll_create", 236 },
	{ "epoll_create1", 315 },
	{ "epoll_ctl", 237 },
	{ "epoll_ctl_old", __PNR_epoll_ctl_old },
	{ "epoll_pwait", 303 },
	{ "epoll_wait", 238 },
	{ "epoll_wait_old", __PNR_epoll_wait_old },
	{ "eventfd", 307 },
	{ "eventfd2", 314 },
	{ "execve", 11 },
	{ "execveat", 362 },
	{ "exit", 1 },
	{ "exit_group", 234 },
	{ "faccessat", 298 },
	{ "faccessat2", 439 },
	{ "fadvise64", 233 },
	{ "fadvise64_64", __PNR_fadvise64_64 },
	{ "fallocate", 309 },
	{ "fanotify_init", 323 },
	{ "fanotify_mark", 324 },
	{ "fchdir", 133 },
	{ "fchmod", 94 },
	{ "fchmodat", 297 },
	{ "fchown", 95 },
	{ "fchown32", __PNR_fchown32 },
	{ "fchownat", 289 },
	{ "fcntl", 55 },
	{ "fcntl64", __PNR_fcntl64 },
	{ "fdatasync", 148 },
	{ "fgetxattr", 214 },
	{ "finit_module", 353 },
	{ "flistxattr", 217 },
	{ "flock", 143 },
	{ "fork", 2 },
	{ "fremovexattr", 220 },
	{ "fsconfig", 431 },
	{ "fsetxattr", 211 },
	{ "fsmount", 432 },
	{ "fsopen", 430 },
	{ "fspick", 433 },
	{ "fstat", 108 },
	{ "fstat64", __PNR_fstat64 },
	{ "fstatat64", __PNR_fstatat64 },
	{ "fstatfs", 100 },
	{ "fstatfs64", 253 },
	{ "fsync", 118 },
	{ "ftime", 35 },
	{ "ftruncate", 93 },
	{ "ftruncate64", __PNR_ftruncate64 },
	{ "futex", 221 },
	{ "futex_time64", __PNR_futex_time64 },
	{ "futimesat", 290 },
	{ "get_kernel_syms", 130 },
	{ "get_mempolicy", 260 },
	{ "get_robust_list", 299 },
	{ "get_thread_area", __PNR_get_thread_area },
	{ "get_tls", __PNR_get_tls },
	{ "getcpu", 302 },
	{ "getcwd", 182 },
	{ "getdents", 141 },
	{ "getdents64", 202 },
	{ "getegid", 50 },
	{ "getegid32", __PNR_getegid32 },
	{ "geteuid", 49 },
	{ "geteuid32", __PNR_geteuid32 },
	{ "getgid", 47 },
	{ "getgid32", __PNR_getgid32 },
	{ "getgroups", 80 },
	{ "getgroups32", __PNR_getgroups32 },
	{ "getitimer", 105 },
	{ "getpeername", 332 },
	{ "getpgid", 132 },
	{ "getpgrp", 65 },
	{ "getpid", 20 },
	{ "getpmsg", 187 },
	{ "getppid", 64 },
	{ "getpriority", 96 },
	{ "getrandom", 359 },
	{ "getresgid", 170 },
	{ "getresgid32", __PNR_getresgid32 },
	{ "getresuid", 165 },
	{ "getresuid32", __PNR_getresuid32 },
	{ "getrlimit", 76 },
	{ "getrusage", 77 },
	{ "getsid", 147 },
	{ "getsockname", 331 },
	{ "getsockopt", 340 },
	{ "gettid", 207 },
	{ "gettimeofday", 78 },
	{ "getuid", 24 },
	{ "getuid32", __PNR_getuid32 },
	{ "getxattr", 212 },
	{ "gtty", 32 },
	{ "idle", 112 },
	{ "init_module", 128 },
	{ "inotify_add_watch", 276 },
	{ "inotify_init", 275 },
	{ "inotify_init1", 318 },
	{ "inotify_rm_watch", 277 },
	{ "io_cancel", 231 },
	{ "io_destroy", 228 },
	{ "io_getevents", 229 },
	{ "io_pgetevents", 388 },
	{ "io_pgetevents_time64", __PNR_io_pgetevents_time64 },
	{ "io_setup", 227 },
	{ "io_submit", 230 },
	{ "io_uring_setup", 425 },
	{ "io_uring_enter", 426 },
	{ "io_uring_register", 427 },
	{ "ioctl", 54 },
	{ "ioperm", 101 },
	{ "iopl", 110 },
	{ "ioprio_get", 274 },
	{ "ioprio_set", 273 },
	{ "ipc", 117 },
	{ "kcmp", 354 },
	{ "kexec_file_load", 382 },
	{ "kexec_load", 268 },
	{ "keyctl", 271 },
	{ "kill", 37 },
	{ "lchown", 16 },
	{ "lchown32", __PNR_lchown32 },
	{ "lgetxattr", 213 },
	{ "link", 9 },
	{ "linkat", 294 },
	{ "listen", 329 },
	{ "listxattr", 215 },
	{ "llistxattr", 216 },
	{ "lock", 53 },
	{ "lookup_dcookie", 235 },
	{ "lremovexattr", 219 },
	{ "lseek", 19 },
	{ "lsetxattr", 210 },
	{ "lstat", 107 },
	{ "lstat64", __PNR_lstat64 },
	{ "madvise", 205 },
	{ "mbind", 259 },
	{ "membarrier", 365 },
	{ "memfd_create", 360 },
	{ "migrate_pages", 258 },
	{ "mincore", 206 },
	{ "mkdir", 39 },
	{ "mkdirat", 287 },
	{ "mknod", 14 },
	{ "mknodat", 288 },
	{ "mlock", 150 },
	{ "mlock2", 378 },
	{ "mlockall", 152 },
	{ "mmap", 90 },
	{ "mmap2", __PNR_mmap2 },
	{ "modify_ldt", 123 },
	{ "mount", 21 },
	{ "move_mount", 429 },
	{ "move_pages", 301 },
	{ "mprotect", 125 },
	{ "mpx", 56 },
	{ "mq_getsetattr", 267 },
	{ "mq_notify", 266 },
	{ "mq_open", 262 },
	{ "mq_timedreceive", 265 },
	{ "mq_timedreceive_time64", __PNR_mq_timedreceive_time64 },
	{ "mq_timedsend", 264 },
	{ "mq_timedsend_time64", __PNR_mq_timedsend_time64 },
	{ "mq_unlink", 263 },
	{ "mremap", 163 },
	{ "msgctl", 402 },
	{ "msgget", 399 },
	{ "msgrcv", 401 },
	{ "msgsnd", 400 },
	{ "msync", 144 },
	{ "multiplexer", 201 },
	{ "munlock", 151 },
	{ "munlockall", 153 },
	{ "munmap", 91 },
	{ "name_to_handle_at", 345 },
	{ "nanosleep", 162 },
	{ "newfstatat", 291 },
	{ "nfsservctl", 168 },
	{ "nice", 34 },
	{ "oldfstat", 28 },
	{ "oldlstat", 84 },
	{ "oldolduname", 59 },
	{ "oldstat", 18 },
	{ "olduname", 109 },
	{ "oldwait4", __PNR_oldwait4 },
	{ "open", 5 },
	{ "open_by_handle_at", 346 },
	{ "open_tree", 428 },
	{ "openat", 286 },
	{ "openat2", 437 },
	{ "pause", 29 },
	{ "pciconfig_iobase", 200 },
	{ "pciconfig_read", 198 },
	{ "pciconfig_write", 199 },
	{ "perf_event_open", 319 },
	{ "personality", 136 },
	{ "pidfd_open", 434 },
	{ "pidfd_send_signal", 424 },
	{ "pipe", 42 },
	{ "pipe2", 317 },
	{ "pivot_root", 203 },
	{ "pkey_alloc", 384 },
	{ "pkey_free", 385 },
	{ "pkey_mprotect", 386 },
	{ "poll", 167 },
	{ "ppoll", 281 },
	{ "ppoll_time64", __PNR_ppoll_time64 },
	{ "prctl", 171 },
	{ "pread64", 179 },
	{ "preadv", 320 },
	{ "preadv2", 380 },
	{ "prlimit64", 325 },
	{ "process_vm_readv", 351 },
	{ "process_vm_writev", 352 },
	{ "prof", 44 },
	{ "profil", 98 },
	{ "pselect6", 280 },
	{ "pselect6_time64", __PNR_pselect6_time64 },
	{ "ptrace", 26 },
	{ "putpmsg", 188 },
	{ "pwrite64", 180 },
	{ "pwritev", 321 },
	{ "pwritev2", 381 },
	{ "query_module", 166 },
	{ "quotactl", 131 },
	{ "read", 3 },
	{ "readahead", 191 },
	{ "readdir", 89 },
	{ "readlink", 85 },
	{ "readlinkat", 296 },
	{ "readv", 145 },
	{ "reboot", 88 },
	{ "recv", 336 },
	{ "recvfrom", 337 },
	{ "recvmmsg", 343 },
	{ "recvmmsg_time64", __PNR_recvmmsg_time64 },
	{ "recvmsg", 342 },
	{ "remap_file_pages", 239 },
	{ "removexattr", 218 },
	{ "rename", 38 },
	{ "renameat", 293 },
	{ "renameat2", 357 },
	{ "request_key", 270 },
	{ "restart_syscall", 0 },
	{ "rmdir", 40 },
	{ "rseq", 387 },
	{ "rt_sigaction", 173 },
	{ "rt_sigpending", 175 },
	{ "rt_sigprocmask", 174 },
	{ "rt_sigqueueinfo", 177 },
	{ "rt_sigreturn", 172 },
	{ "rt_sigsuspend", 178 },
	{ "rt_sigtimedwait", 176 },
	{ "rt_sigtimedwait_time64", __PNR_rt_sigtimedwait_time64 },
	{ "rt_tgsigqueueinfo", 322 },
	{ "rtas", 255 },
	{ "s390_guarded_storage", __PNR_s390_guarded_storage },
	{ "s390_pci_mmio_read", __PNR_s390_pci_mmio_read },
	{ "s390_pci_mmio_write", __PNR_s390_pci_mmio_write },
	{ "s390_runtime_instr", __PNR_s390_runtime_instr },
	{ "s390_sthyi", __PNR_s390_sthyi },
	{ "sched_get_priority_max", 159 },
	{ "sched_get_priority_min", 160 },
	{ "sched_getaffinity", 223 },
	{ "sched_getattr", 356 },
	{ "sched_getparam", 155 },
	{ "sched_getscheduler", 157 },
	{ "sched_rr_get_interval", 161 },
	{ "sched_rr_get_interval_time64", __PNR_sched_rr_get_interval_time64 },
	{ "sched_setaffinity", 222 },
	{ "sched_setattr", 355 },
	{ "sched_setparam", 154 },
	{ "sched_setscheduler", 156 },
	{ "sched_yield", 158 },
	{ "seccomp", 358 },
	{ "security", __PNR_security },
	{ "select", 82 },
	{ "semctl", 394 },
	{ "semget", 393 },
	{ "semop", __PNR_semop },
	{ "semtimedop", 392 },
	{ "semtimedop_time64", __PNR_semtimedop_time64 },
	{ "send", 334 },
	{ "sendfile", 186 },
	{ "sendfile64", __PNR_sendfile64 },
	{ "sendmmsg", 349 },
	{ "sendmsg", 341 },
	{ "sendto", 335 },
	{ "set_mempolicy", 261 },
	{ "set_robust_list", 300 },
	{ "set_thread_area", __PNR_set_thread_area },
	{ "set_tid_address", 232 },
	{ "set_tls", __PNR_set_tls },
	{ "setdomainname", 121 },
	{ "setfsgid", 139 },
	{ "setfsgid32", __PNR_setfsgid32 },
	{ "setfsuid", 138 },
	{ "setfsuid32", __PNR_setfsuid32 },
	{ "setgid", 46 },
	{ "setgid32", __PNR_setgid32 },
	{ "setgroups", 81 },
	{ "setgroups32", __PNR_setgroups32 },
	{ "sethostname", 74 },
	{ "setitimer", 104 },
	{ "setns", 350 },
	{ "setpgid", 57 },
	{ "setpriority", 97 },
	{ "setregid", 71 },
	{ "setregid32", __PNR_setregid32 },
	{ "setresgid", 169 },
	{ "setresgid32", __PNR_setresgid32 },
	{ "setresuid", 164 },
	{ "setresuid32", __PNR_setresuid32 },
	{ "setreuid", 70 },
	{ "setreuid32", __PNR_setreuid32 },
	{ "setrlimit", 75 },
	{ "setsid", 66 },
	{ "setsockopt", 339 },
	{ "settimeofday", 79 },
	{ "setuid", 23 },
	{ "setuid32", __PNR_setuid32 },
	{ "setxattr", 209 },
	{ "sgetmask", 68 },
	{ "shmat", 397 },
	{ "shmctl", 396 },
	{ "shmdt", 398 },
	{ "shmget", 395 },
	{ "shutdown", 338 },
	{ "sigaction", 67 },
	{ "sigaltstack", 185 },
	{ "signal", 48 },
	{ "signalfd", 305 },
	{ "signalfd4", 313 },
	{ "sigpending", 73 },
	{ "sigprocmask", 126 },
	{ "sigreturn", 119 },
	{ "sigsuspend", 72 },
	{ "socket", 326 },
	{ "socketcall", 102 },
	{ "socketpair", 333 },
	{ "splice", 283 },
	{ "spu_create", 279 },
	{ "spu_run", 278 },
	{ "ssetmask", 69 },
	{ "stat", 106 },
	{ "stat64", __PNR_stat64 },
	{ "statfs", 99 },
	{ "statfs64", 252 },
	{ "statx", 383},
	{ "stime", 25 },
	{ "stty", 31 },
	{ "subpage_prot", 310 },
	{ "swapcontext", 249 },
	{ "swapoff", 115 },
	{ "swapon", 87 },
	{ "switch_endian", 363 },
	{ "symlink", 83 },
	{ "symlinkat", 295 },
	{ "sync", 36 },
	{ "sync_file_range", __PNR_sync_file_range },
	{ "sync_file_range2", 308 },
	{ "syncfs", 348 },
	{ "syscall", __PNR_syscall },
	{ "sys_debug_setcontext", 256 },
	{ "sysfs", 135 },
	{ "sysinfo", 116 },
	{ "syslog", 103 },
	{ "sysmips", __PNR_sysmips },
	{ "tee", 284 },
	{ "tgkill", 250 },
	{ "time", 13 },
	{ "timer_create", 240 },
	{ "timer_delete", 244 },
	{ "timer_getoverrun", 243 },
	{ "timer_gettime", 242 },
	{ "timer_gettime64", __PNR_timer_gettime64 },
	{ "timer_settime", 241 },
	{ "timer_settime64", __PNR_timer_settime64 },
	{ "timerfd", __PNR_timerfd },
	{ "timerfd_create", 306 },
	{ "timerfd_gettime", 312 },
	{ "timerfd_gettime64", __PNR_timerfd_gettime64 },
	{ "timerfd_settime", 311 },
	{ "timerfd_settime64", __PNR_timerfd_settime64 },
	{ "times", 43 },
	{ "tkill", 208 },
	{ "truncate", 92 },
	{ "truncate64", __PNR_truncate64 },
	{ "tuxcall", 225 },
	{ "ugetrlimit", 190 },
	{ "ulimit", 58 },
	{ "umask", 60 },
	{ "umount", 22 },
	{ "umount2", 52 },
	{ "uname", 122 },
	{ "unlink", 10 },
	{ "unlinkat", 292 },
	{ "unshare", 282 },
	{ "uselib", 86 },
	{ "userfaultfd", 364 },
	{ "usr26", __PNR_usr26 },
	{ "usr32", __PNR_usr32 },
	{ "ustat", 62 },
	{ "utime", 30 },
	{ "utimensat", 304 },
	{ "utimensat_time64", __PNR_utimensat_time64 },
	{ "utimes", 251 },
	{ "vfork", 189 },
	{ "vhangup", 111 },
	{ "vm86", 113 },
	{ "vm86old", __PNR_vm86old },
	{ "vmsplice", 285 },
	{ "vserver", __PNR_vserver },
	{ "wait4", 114 },
	{ "waitid", 272 },
	{ "waitpid", 7 },
	{ "write", 4 },
	{ "writev", 146 },
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
int ppc64_syscall_resolve_name(const char *name)
{
	unsigned int iter;
	const struct arch_syscall_def *table = ppc64_syscall_table;

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
const char *ppc64_syscall_resolve_num(int num)
{
	unsigned int iter;
	const struct arch_syscall_def *table = ppc64_syscall_table;

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
const struct arch_syscall_def *ppc64_syscall_iterate(unsigned int spot)
{
	/* XXX - no safety checks here */
	return &ppc64_syscall_table[spot];
}
