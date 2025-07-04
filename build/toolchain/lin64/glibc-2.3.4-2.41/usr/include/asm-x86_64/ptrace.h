#ifndef _X86_64_PTRACE_H
#define _X86_64_PTRACE_H

#if defined(__ASSEMBLY__) || defined(__FRAME_OFFSETS) 
#define R15 0
#define R14 8
#define R13 16
#define R12 24
#define RBP 36
#define RBX 40
/* arguments: interrupts/non tracing syscalls only save upto here*/
#define R11 48
#define R10 56	
#define R9 64
#define R8 72
#define RAX 80
#define RCX 88
#define RDX 96
#define RSI 104
#define RDI 112
#define ORIG_RAX 120       /* = ERROR */ 
/* end of arguments */ 	
/* cpu exception frame or undefined in case of fast syscall. */
#define RIP 128
#define CS 136
#define EFLAGS 144
#define RSP 152
#define SS 160
#define ARGOFFSET R11
#endif /* __ASSEMBLY__ */

/* top of stack page */ 
#define FRAME_SIZE 168

/* options set using PTRACE_SETOPTIONS */
#define PTRACE_O_TRACESYSGOOD     0x00000001

#ifndef __ASSEMBLY__ 

struct pt_regs {
	unsigned long r15;
	unsigned long r14;
	unsigned long r13;
	unsigned long r12;
	unsigned long rbp;
	unsigned long rbx;
/* arguments: non interrupts/non tracing syscalls only save upto here*/
 	unsigned long r11;
	unsigned long r10;	
	unsigned long r9;
	unsigned long r8;
	unsigned long rax;
	unsigned long rcx;
	unsigned long rdx;
	unsigned long rsi;
	unsigned long rdi;
	unsigned long orig_rax;
/* end of arguments */ 	
/* cpu exception frame or undefined */
	unsigned long rip;
	unsigned long cs;
	unsigned long eflags; 
	unsigned long rsp; 
	unsigned long ss;
/* top of stack page */ 
};

#endif

/* Arbitrarily choose the same ptrace numbers as used by the Sparc code. */
#define PTRACE_GETREGS            12
#define PTRACE_SETREGS            13
#define PTRACE_GETFPREGS          14
#define PTRACE_SETFPREGS          15
#define PTRACE_GETFPXREGS         18
#define PTRACE_SETFPXREGS         19

/* only useful for access 32bit programs */
#define PTRACE_GET_THREAD_AREA    25
#define PTRACE_SET_THREAD_AREA    26

#define PTRACE_ARCH_PRCTL	30	/* arch_prctl for child */


#endif
