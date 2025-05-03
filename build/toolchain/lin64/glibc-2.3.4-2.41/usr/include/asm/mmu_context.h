#ifndef __ASM_STUB_MMU_CONTEXT_H__
# define __ASM_STUB_MMU_CONTEXT_H__
# if defined __x86_64__
#  include <asm-x86_64/mmu_context.h>
# endif
# if defined __i386__
#  error <asm-i386/mmu_context.h> does not exist
# endif
#endif
