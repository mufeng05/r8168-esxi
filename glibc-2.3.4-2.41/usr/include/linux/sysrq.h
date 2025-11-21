/* -*- linux-c -*-
 *
 *	$Id: sysrq.h,v 1.2 2003/12/05 21:45:48 arjanv Exp $
 *
 *	Linux Magic System Request Key Hacks
 *
 *	(c) 1997 Martin Mares <mj@atrey.karlin.mff.cuni.cz>
 *
 *	(c) 2000 Crutcher Dunnavant <crutcher+kernel@datastacks.com>
 *	overhauled to use key registration
 *	based upon discusions in irc://irc.openprojects.net/#kernelnewbies
 */

#include <linux/config.h>

#define EMERG_SYNC 1
#define EMERG_REMOUNT 2
