#ifndef __ASM_STUB_FIXMAP_H__
# define __ASM_STUB_FIXMAP_H__
# if defined __x86_64__
#  include <asm-x86_64/fixmap.h>
# endif
# if defined __i386__
#  error <asm-i386/fixmap.h> does not exist
# endif
#endif
