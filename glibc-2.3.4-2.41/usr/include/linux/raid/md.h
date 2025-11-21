/*
   md.h : Multiple Devices driver for Linux
          Copyright (C) 1996-98 Ingo Molnar, Gadi Oxman
          Copyright (C) 1994-96 Marc ZYNGIER
	  <zyngier@ufr-info-p7.ibp.fr> or
	  <maz@gloups.fdn.fr>
	  
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.
   
   You should have received a copy of the GNU General Public License
   (for example /usr/src/linux/COPYING); if not, write to the Free
   Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  
*/

#ifndef _MD_H
#define _MD_H

#include <linux/fs.h>
#include <linux/blkdev.h>
#include <asm/semaphore.h>
#include <linux/major.h>
#include <linux/ioctl.h>
#include <linux/types.h>
#include <asm/bitops.h>
#include <linux/module.h>
#include <linux/hdreg.h>
#include <linux/proc_fs.h>
#include <linux/smp_lock.h>
#include <net/checksum.h>
#include <linux/random.h>
#include <linux/kernel_stat.h>
#include <asm/io.h>

#include <linux/raid/md_compatible.h>
/*
 * 'md_p.h' holds the 'physical' layout of RAID devices
 * 'md_u.h' holds the user <=> kernel API
 *
 * 'md_k.h' holds kernel internal definitions
 */

#include <linux/raid/md_p.h>
#include <linux/raid/md_u.h>
#include <linux/raid/md_k.h>

/*
 * Different major versions are not compatible.
 * Different minor versions are only downward compatible.
 * Different patchlevel versions are downward and upward compatible.
 */
#define MD_MAJOR_VERSION                0
#define MD_MINOR_VERSION                90
#define MD_PATCHLEVEL_VERSION           0


#endif 

