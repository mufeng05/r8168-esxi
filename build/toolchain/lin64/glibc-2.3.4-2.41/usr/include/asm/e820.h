#ifndef __ASM_STUB_E820_H__
# define __ASM_STUB_E820_H__
# if defined __x86_64__
#  include <asm-x86_64/e820.h>
# endif
# if defined __i386__
#  error <asm-i386/e820.h> does not exist
# endif
#endif
