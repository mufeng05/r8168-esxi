#ifndef __ASM_STUB_HIGHMEM_H__
# define __ASM_STUB_HIGHMEM_H__
# if defined __x86_64__
#  error <asm-x86_64/highmem.h> does not exist
# endif
# if defined __i386__
#  include <asm-i386/highmem.h>
# endif
#endif
