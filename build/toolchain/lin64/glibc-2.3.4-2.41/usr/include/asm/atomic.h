#ifndef __ASM_STUB_ATOMIC_H__
# define __ASM_STUB_ATOMIC_H__
# if defined __x86_64__
#  include <asm-x86_64/atomic.h>
# endif
# if defined __i386__
#  include <asm-i386/atomic.h>
# endif
#endif
