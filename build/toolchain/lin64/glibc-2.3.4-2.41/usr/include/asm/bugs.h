#ifndef __ASM_STUB_BUGS_H__
# define __ASM_STUB_BUGS_H__
# if defined __x86_64__
#  include <asm-x86_64/bugs.h>
# endif
# if defined __i386__
#  error <asm-i386/bugs.h> does not exist
# endif
#endif
