/*
 * linux/include/linux/hfs_sysdep.h
 *
 * Copyright (C) 1996-1997  Paul H. Hargrove
 * This file may be distributed under the terms of the GNU General Public License.
 *
 * This file contains constants, types and inline
 * functions for various system dependent things.
 *
 * "XXX" in a comment is a note to myself to consider changing something.
 *
 * In function preconditions the term "valid" applied to a pointer to
 * a structure means that the pointer is non-NULL and the structure it
 * points to has all fields initialized to consistent values.
 */

#ifndef _HFS_SYSDEP_H
#define _HFS_SYSDEP_H

#include <linux/types.h>
#include <linux/fs.h>

#include <endian.h>
#include <byteswap.h>
#include <asm/unaligned.h>


#undef offsetof
#define offsetof(TYPE, MEMB) ((size_t) &((TYPE *)0)->MEMB)

/* Typedefs for integer types by size and signedness */
typedef __u8            hfs_u8;
typedef __u16           hfs_u16;
typedef __u32           hfs_u32;
typedef __s8            hfs_s8;
typedef __s16           hfs_s16;
typedef __s32           hfs_s32;

/* Typedefs for unaligned integer types */
typedef unsigned char hfs_byte_t;
typedef unsigned char hfs_word_t[2];
typedef unsigned char hfs_lword_t[4];



/*
 * HFS structures have fields aligned to 16-bit boundaries.
 * So, 16-bit get/put are easy while 32-bit get/put need
 * some care on architectures like the DEC Alpha.
 *
 * In what follows:
 *	ns  = 16-bit integer in network byte-order w/ 16-bit alignment
 *	hs  = 16-bit integer in host byte-order w/ 16-bit alignment
 *	nl  = 32-bit integer in network byte-order w/ unknown alignment
 *	hl  = 32-bit integer in host byte-order w/ unknown alignment
 *	anl = 32-bit integer in network byte-order w/ 32-bit alignment
 *	ahl = 32-bit integer in host byte-order w/ 32-bit alignment
 * Example: hfs_get_hl() gets an unaligned 32-bit integer converting
 *	it to host byte-order.
 */
#define hfs_get_hs(addr)	ntohs(*((hfs_u16 *)(addr)))
#define hfs_get_ns(addr)	(*((hfs_u16 *)(addr)))
#define hfs_get_hl(addr)	ntohl(get_unaligned((hfs_u32 *)(addr)))
#define hfs_get_nl(addr)	get_unaligned((hfs_u32 *)(addr))
#define hfs_get_ahl(addr)	ntohl(*((hfs_u32 *)(addr)))
#define hfs_get_anl(addr)	(*((hfs_u32 *)(addr)))
#define hfs_put_hs(val, addr) 	((void)(*((hfs_u16 *)(addr)) = ntohs(val)))
#define hfs_put_ns(val, addr) 	((void)(*((hfs_u16 *)(addr)) = (val)))
#define hfs_put_hl(val, addr) 	put_unaligned(htonl(val), (hfs_u32 *)(addr))
#define hfs_put_nl(val, addr) 	put_unaligned((val), (hfs_u32 *)(addr))
#define hfs_put_ahl(val, addr) 	((void)(*((hfs_u32 *)(addr)) = ntohl(val)))
#define hfs_put_anl(val, addr) 	((void)(*((hfs_u32 *)(addr)) = (val)))

#endif
