#ifndef _LINUX_ELFCORE_H
#define _LINUX_ELFCORE_H

#include <linux/types.h>
#include <linux/signal.h>
#include <linux/time.h>
#include <linux/ptrace.h>
#include <asm/user.h>

struct elf_siginfo
{
	int	si_signo;			/* signal number */
	int	si_code;			/* extra code */
	int	si_errno;			/* errno */
};

#include <asm/elf.h>

typedef elf_greg_t greg_t;
typedef elf_gregset_t gregset_t;
typedef elf_fpregset_t fpregset_t;
typedef elf_fpxregset_t fpxregset_t;
#define NGREG ELF_NGREG

/*
 * Definitions to generate Intel SVR4-like core files.
 * These mostly have the same names as the SVR4 types with "elf_"
 * tacked on the front to prevent clashes with linux definitions,
 * and the typedef forms have been avoided.  This is mostly like
 * the SVR4 structure, but more Linuxy, with things that Linux does
 * not support and which gdb doesn't really use excluded.
 * Fields present but not used are marked with "XXX".
 */
struct elf_prstatus
{
#if 0
	long	pr_flags;	/* XXX Process flags */
	short	pr_why;		/* XXX Reason for process halt */
	short	pr_what;	/* XXX More detailed reason */
#endif
	struct elf_siginfo pr_info;	/* Info associated with signal */
	short	pr_cursig;		/* Current signal */
	unsigned long pr_sigpend;	/* Set of pending signals */
	unsigned long pr_sighold;	/* Set of held signals */
#if 0
	struct sigaltstack pr_altstack;	/* Alternate stack info */
	struct sigaction pr_action;	/* Signal action for current sig */
#endif
	pid_t	pr_pid;
	pid_t	pr_ppid;
	pid_t	pr_pgrp;
	pid_t	pr_sid;
	struct timeval pr_utime;	/* User time */
	struct timeval pr_stime;	/* System time */
	struct timeval pr_cutime;	/* Cumulative user time */
	struct timeval pr_cstime;	/* Cumulative system time */
#if 0
	long	pr_instr;		/* Current instruction */
#endif
	elf_gregset_t pr_reg;	/* GP registers */
	int pr_fpvalid;		/* True if math co-processor being used.  */
};

#define ELF_PRARGSZ	(80)	/* Number of chars for args */

struct elf_prpsinfo
{
	char	pr_state;	/* numeric process state */
	char	pr_sname;	/* char for pr_state */
	char	pr_zomb;	/* zombie */
	char	pr_nice;	/* nice val */
	unsigned long pr_flag;	/* flags */
	__kernel_uid_t	pr_uid;
	__kernel_gid_t	pr_gid;
	pid_t	pr_pid, pr_ppid, pr_pgrp, pr_sid;
	/* Lots missing */
	char	pr_fname[16];	/* filename of executable */
	char	pr_psargs[ELF_PRARGSZ];	/* initial part of arg list */
};

typedef struct elf_prstatus prstatus_t;
typedef struct elf_prpsinfo prpsinfo_t;
#define PRARGSZ ELF_PRARGSZ 

#endif /* _LINUX_ELFCORE_H */
