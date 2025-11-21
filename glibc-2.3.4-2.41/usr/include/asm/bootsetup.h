#ifndef __ASM_STUB_BOOTSETUP_H__
# define __ASM_STUB_BOOTSETUP_H__
# if defined __x86_64__
#  include <asm-x86_64/bootsetup.h>
# endif
# if defined __i386__
#  error <asm-i386/bootsetup.h> does not exist
# endif
#endif
