#ifndef __ASM_STUB_DESC_H__
# define __ASM_STUB_DESC_H__
# if defined __x86_64__
#  include <asm-x86_64/desc.h>
# endif
# if defined __i386__
#  error <asm-i386/desc.h> does not exist
# endif
#endif
