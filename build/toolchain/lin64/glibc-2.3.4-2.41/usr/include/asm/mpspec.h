#ifndef __ASM_STUB_MPSPEC_H__
# define __ASM_STUB_MPSPEC_H__
# if defined __x86_64__
#  include <asm-x86_64/mpspec.h>
# endif
# if defined __i386__
#  error <asm-i386/mpspec.h> does not exist
# endif
#endif
