#ifndef _LINUX_NVRAM_H
#define _LINUX_NVRAM_H

#include <linux/ioctl.h>

/* /dev/nvram ioctls */
#define NVRAM_INIT		_IO('p', 0x40) /* initialize NVRAM and set checksum */
#define	NVRAM_SETCKS	_IO('p', 0x41) /* recalculate checksum */

#endif  /* _LINUX_NVRAM_H */
