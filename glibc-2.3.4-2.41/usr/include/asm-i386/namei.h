/* $Id: namei.h,v 1.2 2003/12/05 22:12:10 arjanv Exp $
 * linux/include/asm-i386/namei.h
 *
 * Included from linux/fs/namei.c
 */

#ifndef __I386_NAMEI_H
#define __I386_NAMEI_H

#include <linux/config.h>

/*
 * The base directory for our emulations.
 *  - sparc uses usr/gmemul here.
 */
#define I386_EMUL_BASE		"emul/"

/*
 * We emulate quite a lot operting systems...
 */
#define I386_SVR4_EMUL		I386_EMUL_BASE "/svr4/"
#define I386_SVR3_EMUL		I386_EMUL_BASE "/svr3/"
#define I386_SCOSVR3_EMUL	I386_EMUL_BASE "/sco/"
#define I386_OSR5_EMUL		I386_EMUL_BASE "/osr5/"
#define I386_WYSEV386_EMUL	I386_EMUL_BASE "/wyse/"
#define I386_ISCR4_EMUL		I386_EMUL_BASE "/isc/"
#define I386_BSD_EMUL		I386_EMUL_BASE "/bsd/"
#define I386_XENIX_EMUL		I386_EMUL_BASE "/xenix/"
#define I386_SOLARIS_EMUL	I386_EMUL_BASE "/solaris/"
#define I386_UW7_EMUL		I386_EMUL_BASE "/uw7/"


#endif /* __I386_NAMEI_H */
