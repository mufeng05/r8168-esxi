#ifndef __ASM_STUB_OFFSET_H__
# define __ASM_STUB_OFFSET_H__
# if defined __x86_64__
#  include <asm-x86_64/offset.h>
# endif
# if defined __i386__
#  error <asm-i386/offset.h> does not exist
# endif
#endif
