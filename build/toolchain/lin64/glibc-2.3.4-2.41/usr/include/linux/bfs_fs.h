/*
 *	include/linux/bfs_fs.h - BFS data structures on disk.
 *	Copyright (C) 1999 Tigran Aivazian <tigran@veritas.com>
 */

#ifndef _LINUX_BFS_FS_H
#define _LINUX_BFS_FS_H

#define BFS_BSIZE_BITS		9
#define BFS_BSIZE		(1<<BFS_BSIZE_BITS)

#define BFS_MAGIC		0x1BADFACE
#define BFS_ROOT_INO		2
#define BFS_INODES_PER_BLOCK	8

/* SVR4 vnode type values (bfs_inode->i_vtype) */
#define BFS_VDIR		2
#define BFS_VREG		1

/* BFS inode layout on disk */
struct bfs_inode {
	__u16 i_ino;
	__u16 i_unused;
	__u32 i_sblock;
	__u32 i_eblock;
	__u32 i_eoffset;
	__u32 i_vtype;
	__u32 i_mode;
	__s32 i_uid;
	__s32 i_gid;
	__u32 i_nlink;
	__u32 i_atime;
	__u32 i_mtime;
	__u32 i_ctime;
	__u32 i_padding[4];
};

#define BFS_NAMELEN		14	
#define BFS_DIRENT_SIZE		16
#define BFS_DIRS_PER_BLOCK	32

struct bfs_dirent {
	__u16 ino;
	char name[BFS_NAMELEN];
};

/* BFS superblock layout on disk */
struct bfs_super_block {
	__u32 s_magic;
	__u32 s_start;
	__u32 s_end;
	__s32 s_from;
	__s32 s_to;
	__s32 s_bfrom;
	__s32 s_bto;
	char  s_fsname[6];
	char  s_volume[6];
	__u32 s_padding[118];
};


#endif	/* _LINUX_BFS_FS_H */
