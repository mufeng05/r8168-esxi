#ifndef __ASM_STUB_MSR_H__
# define __ASM_STUB_MSR_H__
# if defined __x86_64__
#  include <asm-x86_64/msr.h>
# endif
# if defined __i386__
#  error <asm-i386/msr.h> does not exist
# endif
#endif
