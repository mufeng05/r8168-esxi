/*****************************************************************************/

/*
 *	istallion.h  -- stallion intelligent multiport serial driver.
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
#ifndef	_ISTALLION_H
#define	_ISTALLION_H
/*****************************************************************************/

/*
 *	Define important driver constants here.
 */
#define	STL_MAXBRDS		4
#define	STL_MAXPANELS		4
#define	STL_MAXPORTS		64
#define	STL_MAXCHANS		(STL_MAXPORTS + 1)
#define	STL_MAXDEVS		(STL_MAXBRDS * STL_MAXPORTS)


/*
 *	Define a set of structures to hold all the board/panel/port info
 *	for our ports. These will be dynamically allocated as required at
 *	driver initialization time.
 */


/*
 *	Define MAGIC numbers used for above structures.
 */
#define	STLI_PORTMAGIC	0xe671c7a1
#define	STLI_BOARDMAGIC	0x4bc6c825

/*****************************************************************************/
#endif
