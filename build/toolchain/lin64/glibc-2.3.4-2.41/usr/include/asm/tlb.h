#ifndef __ASM_STUB_TLB_H__
# define __ASM_STUB_TLB_H__
# if defined __x86_64__
#  include <asm-x86_64/tlb.h>
# endif
# if defined __i386__
#  error <asm-i386/tlb.h> does not exist
# endif
#endif
