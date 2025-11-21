#ifndef _GAMEPORT_H
#define _GAMEPORT_H

/*
 * $Id: gameport.h,v 1.3 2003/12/09 17:52:19 arjanv Exp $
 *
 *  Copyright (c) 1999-2000 Vojtech Pavlik
 *
 *  Sponsored by SuSE
 */

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 * Should you need to contact me, the author, you can do so either by
 * e-mail - mail your message to <vojtech@ucw.cz>, or by paper mail:
 * Vojtech Pavlik, Ucitelska 1576, Prague 8, 182 00 Czech Republic
 */

#define GAMEPORT_MODE_DISABLED		0
#define GAMEPORT_MODE_RAW		1
#define GAMEPORT_MODE_COOKED		2

#define GAMEPORT_ID_VENDOR_ANALOG	0x0001
#define GAMEPORT_ID_VENDOR_MADCATZ	0x0002
#define GAMEPORT_ID_VENDOR_LOGITECH	0x0003
#define GAMEPORT_ID_VENDOR_CREATIVE	0x0004
#define GAMEPORT_ID_VENDOR_GENIUS	0x0005
#define GAMEPORT_ID_VENDOR_INTERACT	0x0006
#define GAMEPORT_ID_VENDOR_MICROSOFT	0x0007
#define GAMEPORT_ID_VENDOR_THRUSTMASTER	0x0008
#define GAMEPORT_ID_VENDOR_GRAVIS	0x0009

#endif
