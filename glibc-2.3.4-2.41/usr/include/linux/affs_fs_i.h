#ifndef _AFFS_FS_I
#define _AFFS_FS_I

#include <linux/a.out.h>

// move this to linux/coda.h!!!
#include <linux/time.h>

#define AFFS_CACHE_SIZE		PAGE_SIZE
//#define AFFS_CACHE_SIZE		(4*4)

#define AFFS_MAX_PREALLOC	32
#define AFFS_LC_SIZE		(AFFS_CACHE_SIZE/sizeof(u32)/2)
#define AFFS_AC_SIZE		(AFFS_CACHE_SIZE/sizeof(struct affs_ext_key)/2)
#define AFFS_AC_MASK		(AFFS_AC_SIZE-1)

#endif
