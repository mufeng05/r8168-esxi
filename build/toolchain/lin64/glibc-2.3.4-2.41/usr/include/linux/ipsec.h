/*
 *	Definitions for the SECurity layer
 *
 *	Author:
 *		Robert Muchsel <muchsel@acm.org>
 *
 *	This program is free software; you can redistribute it and/or
 *	modify it under the terms of the GNU General Public License
 *	as published by the Free Software Foundation; either version
 *	2 of the License, or (at your option) any later version.
 */
 
#ifndef _LINUX_IPSEC_H
#define _LINUX_IPSEC_H

#include <linux/config.h>
#include <linux/socket.h>
#include <net/sock.h>

/* Values for the set/getsockopt calls */

/* These defines are compatible with NRL IPv6, however their semantics
   is different */

#define IPSEC_LEVEL_NONE	-1	/* send plaintext, accept any */
#define IPSEC_LEVEL_DEFAULT	0	/* encrypt/authenticate if possible */
					/* the default MUST be 0, because a */
					/* socket is initialized with 0's */
#define IPSEC_LEVEL_USE		1	/* use outbound, don't require inbound */
#define IPSEC_LEVEL_REQUIRE	2	/* require both directions */
#define IPSEC_LEVEL_UNIQUE	2	/* for compatibility only */


#endif	/* _LINUX_IPSEC_H */
