#ifndef __ASM_STUB_DIV64_H__
# define __ASM_STUB_DIV64_H__
# if defined __x86_64__
#  include <asm-x86_64/div64.h>
# endif
# if defined __i386__
#  error <asm-i386/div64.h> does not exist
# endif
#endif
