/*
 * linux/include/linux/ext3_jbd.h
 *
 * Written by Stephen C. Tweedie <sct@redhat.com>, 1999
 *
 * Copyright 1998--1999 Red Hat corp --- All Rights Reserved
 *
 * This file is part of the Linux kernel and is made available under
 * the terms of the GNU General Public License, version 2, or at your
 * option, any later version, incorporated herein by reference.
 *
 * Ext3-specific journaling extensions.
 */

#ifndef _LINUX_EXT3_JBD_H
#define _LINUX_EXT3_JBD_H

#include <linux/fs.h>
#include <linux/jbd.h>
#include <linux/ext3_fs.h>

/* Define the number of blocks we need to account to a transaction to
 * modify one block of data.
 * 
 * We may have to touch one inode, one bitmap buffer, up to three
 * indirection blocks, the group and superblock summaries, and the data
 * block to complete the transaction.  */

#define EXT3_SINGLEDATA_TRANS_BLOCKS	8

/* Define the minimum size for a transaction which modifies data.  This
 * needs to take into account the fact that we may end up modifying two
 * quota files too (one for the group, one for the user quota).  The
 * superblock only gets updated once, of course, so don't bother
 * counting that again for the quota updates. */

#define EXT3_DATA_TRANS_BLOCKS		(3 * EXT3_SINGLEDATA_TRANS_BLOCKS - 2)

extern int ext3_writepage_trans_blocks(struct inode *inode);

/* Delete operations potentially hit one directory's namespace plus an
 * entire inode, plus arbitrary amounts of bitmap/indirection data.  Be
 * generous.  We can grow the delete transaction later if necessary. */

#define EXT3_DELETE_TRANS_BLOCKS	(2 * EXT3_DATA_TRANS_BLOCKS + 64)

/* Define an arbitrary limit for the amount of data we will anticipate
 * writing to any given transaction.  For unbounded transactions such as
 * write(2) and truncate(2) we can write more than this, but we always
 * start off at the maximum transaction size and grow the transaction
 * optimistically as we go. */

#define EXT3_MAX_TRANS_DATA		64

/* We break up a large truncate or write transaction once the handle's
 * buffer credits gets this low, we need either to extend the
 * transaction or to start a new one.  Reserve enough space here for
 * inode, bitmap, superblock, group and indirection updates for at least
 * one block, plus two quota updates.  Quota allocations are not
 * needed. */

#define EXT3_RESERVE_TRANS_BLOCKS	12

#endif	/* _LINUX_EXT3_JBD_H */
