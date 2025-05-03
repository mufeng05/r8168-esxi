#ifndef __ASM_STUB_CURRENT_H__
# define __ASM_STUB_CURRENT_H__
# if defined __x86_64__
#  include <asm-x86_64/current.h>
# endif
# if defined __i386__
#  error <asm-i386/current.h> does not exist
# endif
#endif
