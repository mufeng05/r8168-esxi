/*****************************************************************************
* sdladrv.h	SDLA Support Module.  Kernel API Definitions.
*
* Author: 	Gideon Hack	
*
* Copyright:	(c) 1995-2000 Sangoma Technologies Inc.
*
*		This program is free software; you can redistribute it and/or
*		modify it under the terms of the GNU General Public License
*		as published by the Free Software Foundation; either version
*		2 of the License, or (at your option) any later version.
* ============================================================================
* Jun 02, 1999 	Gideon Hack	Added support for the S514 PCI adapter.
* Dec 11, 1996	Gene Kozin	Complete overhaul.
* Oct 17, 1996	Gene Kozin	Minor bug fixes.
* Jun 12, 1996	Gene Kozin 	Added support for S503 card.
* Dec 06, 1995	Gene Kozin	Initial version.
*****************************************************************************/
#ifndef	_SDLADRV_H
#define	_SDLADRV_H

#include <linux/version.h>


#define	SDLA_MAXIORANGE	4	/* maximum I/O port range */
#define	SDLA_WINDOWSIZE	0x2000	/* default dual-port memory window size */


#endif	/* _SDLADRV_H */
