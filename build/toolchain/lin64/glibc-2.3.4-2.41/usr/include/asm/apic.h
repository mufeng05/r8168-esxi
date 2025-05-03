#ifndef __ASM_STUB_APIC_H__
# define __ASM_STUB_APIC_H__
# if defined __x86_64__
#  include <asm-x86_64/apic.h>
# endif
# if defined __i386__
#  error <asm-i386/apic.h> does not exist
# endif
#endif
