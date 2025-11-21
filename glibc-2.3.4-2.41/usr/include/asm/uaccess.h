#ifndef __ASM_STUB_UACCESS_H__
# define __ASM_STUB_UACCESS_H__
# if defined __x86_64__
#  include <asm-x86_64/uaccess.h>
# endif
# if defined __i386__
#  error <asm-i386/uaccess.h> does not exist
# endif
#endif
