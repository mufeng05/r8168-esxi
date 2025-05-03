#ifndef __ASM_STUB_CHECKSUM_H__
# define __ASM_STUB_CHECKSUM_H__
# if defined __x86_64__
#  include <asm-x86_64/checksum.h>
# endif
# if defined __i386__
#  error <asm-i386/checksum.h> does not exist
# endif
#endif
