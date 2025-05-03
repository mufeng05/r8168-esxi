#ifndef __ASM_STUB_FPU32_H__
# define __ASM_STUB_FPU32_H__
# if defined __x86_64__
#  include <asm-x86_64/fpu32.h>
# endif
# if defined __i386__
#  error <asm-i386/fpu32.h> does not exist
# endif
#endif
