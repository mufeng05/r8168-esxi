#ifndef __ASM_STUB_MMU_H__
# define __ASM_STUB_MMU_H__
# if defined __x86_64__
#  include <asm-x86_64/mmu.h>
# endif
# if defined __i386__
#  include <asm-i386/mmu.h>
# endif
#endif
