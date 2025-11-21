#ifndef __ASM_STUB_PRCTL_H__
# define __ASM_STUB_PRCTL_H__
# if defined __x86_64__
#  include <asm-x86_64/prctl.h>
# endif
# if defined __i386__
#  error <asm-i386/prctl.h> does not exist
# endif
#endif
