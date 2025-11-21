/*
 * Generic HDLC support routines for Linux
 *
 * Copyright (C) 1999, 2000 Krzysztof Halasa <khc@pm.waw.pl>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#ifndef __HDLC_H
#define __HDLC_H

/* Ioctls - to be changed */
#define HDLCGSLOTMAP	(0x89F4) /* E1/T1 slot bitmap */
#define HDLCGCLOCK	(0x89F5) /* clock sources */
#define HDLCGCLOCKRATE	(0x89F6) /* clock rate */
#define HDLCGMODE	(0x89F7) /* internal to hdlc.c - protocol used */
#define HDLCGLINE	(0x89F8) /* physical interface */
#define HDLCSSLOTMAP	(0x89F9)
#define HDLCSCLOCK	(0x89FA)
#define HDLCSCLOCKRATE	(0x89FB)
#define HDLCSMODE	(0x89FC) /* internal to hdlc.c - select protocol */
#define HDLCPVC		(0x89FD) /* internal to hdlc.c - create/delete PVC */
#define HDLCSLINE	(0x89FE)
#define HDLCRUN		(0x89FF) /* Download firmware and run board */

/* Modes */
#define MODE_NONE	0x00000000 /* Not initialized */
#define MODE_DCE	0x00000080 /* DCE */
#define MODE_HDLC	0x00000100 /* Raw HDLC frames */
#define MODE_CISCO	0x00000200
#define MODE_PPP	0x00000400
#define MODE_FR		0x00000800 /* Any LMI */
#define MODE_FR_ANSI	0x00000801
#define MODE_FR_CCITT	0x00000802
#define MODE_X25	0x00001000
#define MODE_MASK	0x0000FF00
#define MODE_SOFT	0x80000000 /* Driver modes, using hardware HDLC */

/* Lines */
#define LINE_DEFAULT	0x00000000
#define LINE_V35	0x00000001
#define LINE_RS232	0x00000002
#define LINE_X21	0x00000003
#define LINE_T1		0x00000004
#define LINE_E1		0x00000005
#define LINE_MASK	0x000000FF
#define LINE_LOOPBACK	0x80000000 /* On-card loopback */

#define CLOCK_EXT	0	/* External TX and RX clock - DTE */
#define CLOCK_INT	1	/* Internal TX and RX clock - DCE */
#define CLOCK_TXINT	2	/* Internal TX and external RX clock */
#define CLOCK_TXFROMRX	3	/* TX clock derived from external RX clock */


#define HDLC_MAX_MTU 1500	/* Ethernet 1500 bytes */
#define HDLC_MAX_MRU (HDLC_MAX_MTU + 10) /* max 10 bytes for FR */


#endif /* __HDLC_H */
