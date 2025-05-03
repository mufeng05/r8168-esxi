#ifndef __ASM_STUB_KDEBUG_H__
# define __ASM_STUB_KDEBUG_H__
# if defined __x86_64__
#  include <asm-x86_64/kdebug.h>
# endif
# if defined __i386__
#  error <asm-i386/kdebug.h> does not exist
# endif
#endif
