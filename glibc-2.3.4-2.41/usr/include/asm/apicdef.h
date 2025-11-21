#ifndef __ASM_STUB_APICDEF_H__
# define __ASM_STUB_APICDEF_H__
# if defined __x86_64__
#  include <asm-x86_64/apicdef.h>
# endif
# if defined __i386__
#  error <asm-i386/apicdef.h> does not exist
# endif
#endif
