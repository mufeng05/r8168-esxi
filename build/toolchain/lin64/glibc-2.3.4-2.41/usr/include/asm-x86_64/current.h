#ifndef _X86_64_CURRENT_H
#define _X86_64_CURRENT_H

#if !defined(__ASSEMBLY__) 
struct task_struct;

#include <asm/pda.h>

static inline struct task_struct *get_current(void) 
{ 
	struct task_struct *t = read_pda(pcurrent); 
	return t;
} 


static inline struct task_struct *stack_current(void)
{
	struct task_struct *current;
	__asm__("andq %%rsp,%0; ":"=r" (current) : "0" (~8191UL));
	return current;
}


#define current get_current()

#else

#ifndef ASM_OFFSET_H
#include <asm/offset.h> 
#endif

#define GET_CURRENT(reg) movq %gs:(pda_pcurrent),reg

#endif

#endif /* !(_X86_64_CURRENT_H) */
