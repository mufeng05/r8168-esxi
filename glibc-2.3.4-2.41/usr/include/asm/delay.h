#ifndef __ASM_STUB_DELAY_H__
# define __ASM_STUB_DELAY_H__
# if defined __x86_64__
#  include <asm-x86_64/delay.h>
# endif
# if defined __i386__
#  error <asm-i386/delay.h> does not exist
# endif
#endif
