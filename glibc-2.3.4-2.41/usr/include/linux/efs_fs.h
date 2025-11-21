/*
 * efs_fs.h
 *
 * Copyright (c) 1999 Al Smith
 *
 * Portions derived from work (c) 1995,1996 Christian Vogelgsang.
 */

#ifndef __EFS_FS_H__
#define __EFS_FS_H__

#define EFS_VERSION "1.0a"

static const char cprt[] = "EFS: "EFS_VERSION" - (c) 1999 Al Smith <Al.Smith@aeschi.ch.eu.org>";

#include <asm/uaccess.h>

/* 1 block is 512 bytes */
#define	EFS_BLOCKSIZE_BITS	9
#define	EFS_BLOCKSIZE		(1 << EFS_BLOCKSIZE_BITS)

#include <linux/efs_fs_i.h>
#include <linux/efs_dir.h>

#endif /* __EFS_FS_H__ */
