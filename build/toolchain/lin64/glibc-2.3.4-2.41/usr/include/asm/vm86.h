#ifndef __ASM_STUB_VM86_H__
# define __ASM_STUB_VM86_H__
# if defined __x86_64__
#  error <asm-x86_64/vm86.h> does not exist
# endif
# if defined __i386__
#  include <asm-i386/vm86.h>
# endif
#endif
