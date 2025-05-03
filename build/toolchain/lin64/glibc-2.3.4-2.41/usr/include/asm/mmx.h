#ifndef __ASM_STUB_MMX_H__
# define __ASM_STUB_MMX_H__
# if defined __x86_64__
#  include <asm-x86_64/mmx.h>
# endif
# if defined __i386__
#  error <asm-i386/mmx.h> does not exist
# endif
#endif
