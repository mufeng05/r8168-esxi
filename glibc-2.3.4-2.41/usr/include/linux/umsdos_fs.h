#ifndef LINUX_UMSDOS_FS_H
#define LINUX_UMSDOS_FS_H


/*#define UMS_DEBUG 1	// define for check_* functions */
/*#define UMSDOS_DEBUG 1*/
#define UMSDOS_PARANOIA 1

#define UMSDOS_VERSION	0
#define UMSDOS_RELEASE	4

#define UMSDOS_ROOT_INO 1

/* This is the file acting as a directory extension */
#define UMSDOS_EMD_FILE		"--linux-.---"
#define UMSDOS_EMD_NAMELEN	12
#define UMSDOS_PSDROOT_NAME	"linux"
#define UMSDOS_PSDROOT_LEN	5

#ifndef _LINUX_TYPES_H
#include <linux/types.h>
#endif
#ifndef _LINUX_LIMITS_H
#include <linux/limits.h>
#endif
#ifndef _LINUX_DIRENT_H
#include <linux/dirent.h>
#endif
#ifndef _LINUX_IOCTL_H
#include <linux/ioctl.h>
#endif



#endif
