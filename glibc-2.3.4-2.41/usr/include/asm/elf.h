#ifndef __ASM_STUB_ELF_H__
# define __ASM_STUB_ELF_H__
# if defined __x86_64__
#  include <asm-x86_64/elf.h>
# endif
# if defined __i386__
#  include <asm-i386/elf.h>
# endif
#endif
