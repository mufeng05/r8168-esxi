#ifndef __ASM_STUB_SMPLOCK_H__
# define __ASM_STUB_SMPLOCK_H__
# if defined __x86_64__
#  include <asm-x86_64/smplock.h>
# endif
# if defined __i386__
#  error <asm-i386/smplock.h> does not exist
# endif
#endif
