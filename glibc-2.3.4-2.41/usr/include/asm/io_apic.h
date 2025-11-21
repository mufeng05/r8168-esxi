#ifndef __ASM_STUB_IO_APIC_H__
# define __ASM_STUB_IO_APIC_H__
# if defined __x86_64__
#  include <asm-x86_64/io_apic.h>
# endif
# if defined __i386__
#  error <asm-i386/io_apic.h> does not exist
# endif
#endif
