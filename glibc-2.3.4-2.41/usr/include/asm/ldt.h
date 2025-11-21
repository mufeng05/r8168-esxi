#ifndef __ASM_STUB_LDT_H__
# define __ASM_STUB_LDT_H__
# if defined __x86_64__
#  include <asm-x86_64/ldt.h>
# endif
# if defined __i386__
#  include <asm-i386/ldt.h>
# endif
#endif
