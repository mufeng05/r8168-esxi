/*****************************************************************************/

/*
 *	stallion.h  -- stallion multiport serial driver.
 *
 *	Copyright (C) 1996-1998  Stallion Technologies (support@stallion.oz.au).
 *	Copyright (C) 1994-1996  Greg Ungerer.
 *
 *	This program is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation; either version 2 of the License, or
 *	(at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program; if not, write to the Free Software
 *	Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

/*****************************************************************************/
#ifndef	_STALLION_H
#define	_STALLION_H
/*****************************************************************************/

/*
 *	Define important driver constants here.
 */
#define	STL_MAXBRDS		4
#define	STL_MAXPANELS		4
#define	STL_MAXBANKS		8
#define	STL_PORTSPERPANEL	16
#define	STL_MAXPORTS		64
#define	STL_MAXDEVS		(STL_MAXBRDS * STL_MAXPORTS)


/*
 *	Define a set of structures to hold all the board/panel/port info
 *	for our ports. These will be dynamically allocated as required.
 */

/*
 *	Define a ring queue structure for each port. This will hold the
 *	TX data waiting to be output. Characters are fed into this buffer
 *	from the line discipline (or even direct from user space!) and
 *	then fed into the UARTs during interrupts. Will use a classic ring
 *	queue here for this. The good thing about this type of ring queue
 *	is that the head and tail pointers can be updated without interrupt
 *	protection - since "write" code only needs to change the head, and
 *	interrupt code only needs to change the tail.
 */
typedef struct {
	char	*buf;
	char	*head;
	char	*tail;
} stlrq_t;

/*
 *	Define MAGIC numbers used for above structures.
 */
#define	STL_PORTMAGIC	0x5a7182c9
#define	STL_PANELMAGIC	0x7ef621a1
#define	STL_BOARDMAGIC	0xa2267f52

/*****************************************************************************/
#endif
