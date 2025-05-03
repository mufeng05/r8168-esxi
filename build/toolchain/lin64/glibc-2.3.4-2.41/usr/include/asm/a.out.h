#ifndef __ASM_STUB_A_OUT_H__
# define __ASM_STUB_A_OUT_H__
# if defined __x86_64__
#  include <asm-x86_64/a.out.h>
# endif
# if defined __i386__
#  include <asm-i386/a.out.h>
# endif
#endif
