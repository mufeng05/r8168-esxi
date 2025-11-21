#ifndef __ASM_STUB_KMAP_TYPES_H__
# define __ASM_STUB_KMAP_TYPES_H__
# if defined __x86_64__
#  include <asm-x86_64/kmap_types.h>
# endif
# if defined __i386__
#  error <asm-i386/kmap_types.h> does not exist
# endif
#endif
