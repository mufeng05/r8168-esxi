#ifndef __ASM_STUB_SOFTIRQ_H__
# define __ASM_STUB_SOFTIRQ_H__
# if defined __x86_64__
#  include <asm-x86_64/softirq.h>
# endif
# if defined __i386__
#  error <asm-i386/softirq.h> does not exist
# endif
#endif
