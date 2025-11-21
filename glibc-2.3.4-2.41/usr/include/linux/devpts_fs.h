/* -*- linux-c -*- --------------------------------------------------------- *
 *
 * linux/include/linux/devpts_fs.h
 *
 *  Copyright 1998 H. Peter Anvin -- All Rights Reserved
 *
 * This file is part of the Linux kernel and is made available under
 * the terms of the GNU General Public License, version 2, or at your
 * option, any later version, incorporated herein by reference.
 *
 * ------------------------------------------------------------------------- */

/*
 * Prototypes for the pty driver <-> devpts filesystem interface.  Most
 * of this is really just a hack so we can exclude it or build it as a
 * module, and probably should go away eventually.
 */

#ifndef _LINUX_DEVPTS_FS_H
#define _LINUX_DEVPTS_FS_H 1

#include <linux/config.h>
#include <linux/kdev_t.h>
#include <linux/tty.h>

#define unix98_max_ptys               NR_PTYS * UNIX98_NR_MAJORS;


#endif /* _LINUX_DEVPTS_FS_H */
