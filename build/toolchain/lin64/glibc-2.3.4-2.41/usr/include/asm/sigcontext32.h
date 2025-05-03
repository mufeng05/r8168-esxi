#ifndef __ASM_STUB_SIGCONTEXT32_H__
# define __ASM_STUB_SIGCONTEXT32_H__
# if defined __x86_64__
#  include <asm-x86_64/sigcontext32.h>
# endif
# if defined __i386__
#  error <asm-i386/sigcontext32.h> does not exist
# endif
#endif
