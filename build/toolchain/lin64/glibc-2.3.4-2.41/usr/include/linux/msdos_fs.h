#ifndef _LINUX_MSDOS_FS_H
#define _LINUX_MSDOS_FS_H

/*
 * The MS-DOS filesystem constants/structures
 */
#include <linux/fs.h>
#include <linux/stat.h>
#include <linux/fd.h>
#include <asm/types.h>


#define MSDOS_ROOT_INO  1 /* == MINIX_ROOT_INO */
#define SECTOR_SIZE     512 /* sector size (bytes) */
#define SECTOR_BITS	9 /* log2(SECTOR_SIZE) */
#define MSDOS_DPB	(MSDOS_DPS) /* dir entries per block */
#define MSDOS_DPB_BITS	4 /* log2(MSDOS_DPB) */
#define MSDOS_DPS	(SECTOR_SIZE/sizeof(struct msdos_dir_entry))
#define MSDOS_DPS_BITS	4 /* log2(MSDOS_DPS) */
#define MSDOS_DIR_BITS	5 /* log2(sizeof(struct msdos_dir_entry)) */

#define MSDOS_SUPER_MAGIC 0x4d44 /* MD */

#define FAT_CACHE    8 /* FAT cache size */

#define MSDOS_MAX_EXTRA	3 /* tolerate up to that number of clusters which are
			     inaccessible because the FAT is too short */

#define ATTR_RO      1  /* read-only */
#define ATTR_HIDDEN  2  /* hidden */
#define ATTR_SYS     4  /* system */
#define ATTR_VOLUME  8  /* volume label */
#define ATTR_DIR     16 /* directory */
#define ATTR_ARCH    32 /* archived */

#define ATTR_NONE    0 /* no attribute bits */
#define ATTR_UNUSED  (ATTR_VOLUME | ATTR_ARCH | ATTR_SYS | ATTR_HIDDEN)
	/* attribute bits that are copied "as is" */
#define ATTR_EXT     (ATTR_RO | ATTR_HIDDEN | ATTR_SYS | ATTR_VOLUME)
	/* bits that are used by the Windows 95/Windows NT extended FAT */

#define ATTR_DIR_READ_BOTH 512 /* read both short and long names from the
				* vfat filesystem.  This is used by Samba
				* to export the vfat filesystem with correct
				* shortnames. */
#define ATTR_DIR_READ_SHORT 1024

#define CASE_LOWER_BASE 8	/* base is lower case */
#define CASE_LOWER_EXT  16	/* extension is lower case */

#define SCAN_ANY     0  /* either hidden or not */
#define SCAN_HID     1  /* only hidden */
#define SCAN_NOTHID  2  /* only not hidden */
#define SCAN_NOTANY  3  /* test name, then use SCAN_HID or SCAN_NOTHID */

#define DELETED_FLAG 0xe5 /* marks file as deleted when in name[0] */
#define IS_FREE(n) (!*(n) || *(const unsigned char *) (n) == DELETED_FLAG)

#define MSDOS_VALID_MODE (S_IFREG | S_IFDIR | S_IRWXU | S_IRWXG | S_IRWXO)
	/* valid file mode bits */

#define MSDOS_SB(s) (&((s)->u.msdos_sb))
#define MSDOS_I(i) (&((i)->u.msdos_i))

#define MSDOS_NAME 11 /* maximum name length */
#define MSDOS_LONGNAME 256 /* maximum name length */
#define MSDOS_SLOTS 21  /* max # of slots needed for short and long names */
#define MSDOS_DOT    ".          " /* ".", padded to MSDOS_NAME chars */
#define MSDOS_DOTDOT "..         " /* "..", padded to MSDOS_NAME chars */

#define MSDOS_FAT12 4084 /* maximum number of clusters in a 12 bit FAT */

#define EOF_FAT12 0xFF8		/* standard EOF */
#define EOF_FAT16 0xFFF8
#define EOF_FAT32 0xFFFFFF8
#define EOF_FAT(s) (MSDOS_SB(s)->fat_bits == 32 ? EOF_FAT32 : \
	MSDOS_SB(s)->fat_bits == 16 ? EOF_FAT16 : EOF_FAT12)

#define FAT_FSINFO_SIG1		0x41615252
#define FAT_FSINFO_SIG2		0x61417272
#define IS_FSINFO(x)		(CF_LE_L((x)->signature1) == FAT_FSINFO_SIG1	 \
				 && CF_LE_L((x)->signature2) == FAT_FSINFO_SIG2)

/*
 * Inode flags
 */
#define FAT_BINARY_FL		0x00000001 /* File contains binary data */

/*
 * ioctl commands
 */
#define	VFAT_IOCTL_READDIR_BOTH		_IOR('r', 1, struct dirent [2])
#define	VFAT_IOCTL_READDIR_SHORT	_IOR('r', 2, struct dirent [2])

/* 
 * vfat shortname flags
 */
#define VFAT_SFN_DISPLAY_LOWER	0x0001 /* convert to lowercase for display */
#define VFAT_SFN_DISPLAY_WIN95	0x0002 /* emulate win95 rule for display */
#define VFAT_SFN_DISPLAY_WINNT	0x0004 /* emulate winnt rule for display */
#define VFAT_SFN_CREATE_WIN95	0x0100 /* emulate win95 rule for create */
#define VFAT_SFN_CREATE_WINNT	0x0200 /* emulate winnt rule for create */

/*
 * Conversion from and to little-endian byte order. (no-op on i386/i486)
 *
 * Naming: Ca_b_c, where a: F = from, T = to, b: LE = little-endian,
 * BE = big-endian, c: W = word (16 bits), L = longword (32 bits)
 */

#define CF_LE_W(v) le16_to_cpu(v)
#define CF_LE_L(v) le32_to_cpu(v)
#define CT_LE_W(v) cpu_to_le16(v)
#define CT_LE_L(v) cpu_to_le32(v)

struct fat_boot_sector {
	__s8	ignored[3];	/* Boot strap short or near jump */
	__s8	system_id[8];	/* Name - can be used to special case
				   partition manager volumes */
	__u8	sector_size[2];	/* bytes per logical sector */
	__u8	cluster_size;	/* sectors/cluster */
	__u16	reserved;	/* reserved sectors */
	__u8	fats;		/* number of FATs */
	__u8	dir_entries[2];	/* root directory entries */
	__u8	sectors[2];	/* number of sectors */
	__u8	media;		/* media code (unused) */
	__u16	fat_length;	/* sectors/FAT */
	__u16	secs_track;	/* sectors per track */
	__u16	heads;		/* number of heads */
	__u32	hidden;		/* hidden sectors (unused) */
	__u32	total_sect;	/* number of sectors (if sectors == 0) */

	/* The following fields are only used by FAT32 */
	__u32	fat32_length;	/* sectors/FAT */
	__u16	flags;		/* bit 8: fat mirroring, low 4: active fat */
	__u8	version[2];	/* major, minor filesystem version */
	__u32	root_cluster;	/* first cluster in root directory */
	__u16	info_sector;	/* filesystem info sector */
	__u16	backup_boot;	/* backup boot sector */
	__u16	reserved2[6];	/* Unused */
};

struct fat_boot_fsinfo {
	__u32   signature1;	/* 0x41615252L */
	__u32   reserved1[120];	/* Nothing as far as I can tell */
	__u32   signature2;	/* 0x61417272L */
	__u32   free_clusters;	/* Free cluster count.  -1 if unknown */
	__u32   next_cluster;	/* Most recently allocated cluster.
				 * Unused under Linux. */
	__u32   reserved2[4];
};

struct msdos_dir_entry {
	__s8	name[8],ext[3];	/* name and extension */
	__u8	attr;		/* attribute bits */
	__u8    lcase;		/* Case for base and extension */
	__u8	ctime_ms;	/* Creation time, milliseconds */
	__u16	ctime;		/* Creation time */
	__u16	cdate;		/* Creation date */
	__u16	adate;		/* Last access date */
	__u16   starthi;	/* High 16 bits of cluster in FAT32 */
	__u16	time,date,start;/* time, date and first cluster */
	__u32	size;		/* file size (in bytes) */
};

/* Up to 13 characters of the name */
struct msdos_dir_slot {
	__u8    id;		/* sequence number for slot */
	__u8    name0_4[10];	/* first 5 characters in name */
	__u8    attr;		/* attribute byte */
	__u8    reserved;	/* always 0 */
	__u8    alias_checksum;	/* checksum for 8.3 alias */
	__u8    name5_10[12];	/* 6 more characters in name */
	__u16   start;		/* starting cluster number, 0 in long slots */
	__u8    name11_12[4];	/* last 2 characters in name */
};

struct vfat_slot_info {
	int is_long;		       /* was the found entry long */
	int long_slots;		       /* number of long slots in filename */
	int total_slots;	       /* total slots (long and short) */
	loff_t longname_offset;	       /* dir offset for longname start */
	loff_t shortname_offset;       /* dir offset for shortname start */
	int ino;		       /* ino for the file */
};

/* Determine whether this FS has kB-aligned data. */
#define MSDOS_CAN_BMAP(mib) (!(((mib)->cluster_size & 1) || \
    ((mib)->data_start & 1)))

/* Convert attribute bits and a mask to the UNIX mode. */
#define MSDOS_MKMODE(a,m) (m & (a & ATTR_RO ? S_IRUGO|S_IXUGO : S_IRWXUGO))

/* Convert the UNIX mode to MS-DOS attribute bits. */
#define MSDOS_MKATTR(m) ((m & S_IWUGO) ? ATTR_NONE : ATTR_RO)




#endif
