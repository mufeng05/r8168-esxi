#ifndef __ASM_STUB_PDA_H__
# define __ASM_STUB_PDA_H__
# if defined __x86_64__
#  include <asm-x86_64/pda.h>
# endif
# if defined __i386__
#  error <asm-i386/pda.h> does not exist
# endif
#endif
