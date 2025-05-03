#ifndef __ASM_STUB_CALLING_H__
# define __ASM_STUB_CALLING_H__
# if defined __x86_64__
#  include <asm-x86_64/calling.h>
# endif
# if defined __i386__
#  error <asm-i386/calling.h> does not exist
# endif
#endif
