#ifndef __ASM_STUB_MCE_H__
# define __ASM_STUB_MCE_H__
# if defined __x86_64__
#  include <asm-x86_64/mce.h>
# endif
# if defined __i386__
#  error <asm-i386/mce.h> does not exist
# endif
#endif
