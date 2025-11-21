#ifndef __ASM_SYSTEM_H
#define __ASM_SYSTEM_H

#include <linux/config.h>
#include <linux/kernel.h>
#include <asm/segment.h>


#define wbinvd() \
	__asm__ __volatile__ ("wbinvd": : :"memory");


#define nop() __asm__ __volatile__ ("nop")



#endif
