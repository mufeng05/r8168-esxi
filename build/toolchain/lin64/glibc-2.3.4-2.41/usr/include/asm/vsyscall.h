#ifndef __ASM_STUB_VSYSCALL_H__
# define __ASM_STUB_VSYSCALL_H__
# if defined __x86_64__
#  include <asm-x86_64/vsyscall.h>
# endif
# if defined __i386__
#  error <asm-i386/vsyscall.h> does not exist
# endif
#endif
