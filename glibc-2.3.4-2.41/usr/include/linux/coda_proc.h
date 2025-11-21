/*
 * coda_statis.h
 * 
 * CODA operation statistics
 *
 * (c) March, 1998
 * by Michihiro Kuramochi, Zhenyu Xia and Zhanyong Wan
 * zhanyong.wan@yale.edu
 *
 */

#ifndef _CODA_PROC_H
#define _CODA_PROC_H

#include <linux/sysctl.h>
#include <linux/coda_fs_i.h>
#include <linux/coda.h>

/* these four files are presented to show the result of the statistics:
 *
 *	/proc/fs/coda/vfs_stats
 *		      upcall_stats
 *		      permission_stats
 *		      cache_inv_stats
 *
 * these four files are presented to reset the statistics to 0:
 *
 *	/proc/sys/coda/vfs_stats
 *		       upcall_stats
 *		       permission_stats
 *		       cache_inv_stats
 */

/* VFS operation statistics */
struct coda_vfs_stats 
{
	/* file operations */
	int open;
	int flush;
	int release;
	int fsync;

	/* dir operations */
	int readdir;
  
	/* inode operations */
	int create;
	int lookup;
	int link;
	int unlink;
	int symlink;
	int mkdir;
	int rmdir;
	int rename;
	int permission;

	/* symlink operatoins*/
	int follow_link;
	int readlink;
};

struct coda_upcall_stats_entry 
{
  int count;
  unsigned long time_sum;
  unsigned long time_squared_sum;
};



/* cache hits for permissions statistics */
struct coda_permission_stats 
{
	int count;
	int hit_count;
};

/* cache invalidation statistics */
struct coda_cache_inv_stats
{
	int flush;
	int purge_user;
	int zap_dir;
	int zap_file;
	int zap_vnode;
	int purge_fid;
	int replace;
};

#endif /* _CODA_PROC_H */
