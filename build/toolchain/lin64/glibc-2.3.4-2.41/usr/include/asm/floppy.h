#ifndef __ASM_STUB_FLOPPY_H__
# define __ASM_STUB_FLOPPY_H__
# if defined __x86_64__
#  include <asm-x86_64/floppy.h>
# endif
# if defined __i386__
#  error <asm-i386/floppy.h> does not exist
# endif
#endif
