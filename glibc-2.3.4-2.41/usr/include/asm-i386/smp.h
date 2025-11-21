#ifndef __ASM_SMP_H
#define __ASM_SMP_H

/*
 * We need the APIC definitions automatically as part of 'smp.h'
 */
#ifndef ASSEMBLY
#include <linux/config.h>
#include <linux/threads.h>
#include <linux/ptrace.h>
#endif

#ifdef CONFIG_X86_LOCAL_APIC
#ifndef ASSEMBLY
#include <asm/fixmap.h>
#include <asm/bitops.h>
#include <asm/mpspec.h>
#ifdef CONFIG_X86_IO_APIC
#include <asm/io_apic.h>
#endif
#include <asm/apic.h>
#endif
#endif

#ifdef CONFIG_SMP

#define NO_PROC_ID		0xFF		/* No processor magic marker */

/*
 *	This magic constant controls our willingness to transfer
 *	a process across CPUs. Such a transfer incurs misses on the L1
 *	cache, and on a P6 or P5 with multiple L2 caches L2 hits. My
 *	gut feeling is this will vary by board in value. For a board
 *	with separate L2 cache it probably depends also on the RSS, and
 *	for a board with shared L2 cache it ought to decay fast as other
 *	processes are run.
 */
 
#define PROC_CHANGE_PENALTY	15		/* Schedule penalty */

#endif
#endif
