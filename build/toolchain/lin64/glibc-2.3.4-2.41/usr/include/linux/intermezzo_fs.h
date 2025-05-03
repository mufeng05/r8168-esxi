/*
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License as
 *  published by the Free Software Foundation; either version 2 of the
 *  License, or (at your option) any later version.
 *
 *  Copyright (C) 2000 Stelias Computing, Inc.
 *  Copyright (C) 2000 Red Hat, Inc.
 *  Copyright (C) 2000 TurboLinux, Inc.
 *  Copyright (C) 2000 Los Alamos National Laboratory.
 *  Copyright (C) 2001 Tacitus Systems, Inc.
 *  Copyright (C) 2001 Cluster File Systems, Inc. 
 */

#ifndef __INTERMEZZO_FS_H_
#define __INTERMEZZO_FS_H_ 1


#include <asm/types.h>
#include <sys/ioctl.h>
struct lento_vfs_context {
        __u32 slot_offset;
        __u32 recno;
        __u64 kml_offset;
        __u32 flags;
        __u32 updated_time;
};



/* marking flags for fsets */
#define FSET_CLIENT_RO 0x00000001
#define FSET_LENTO_RO  0x00000002
#define FSET_HASPERMIT  0x00000004 /* we have a permit to WB */
#define FSET_INSYNC     0x00000008 /* this fileset is in sync */
#define FSET_PERMIT_WAITING 0x00000010 /* Lento is waiting for permit */
#define FSET_STEAL_PERMIT 0x00000020 /* take permit if Lento is dead */
#define FSET_JCLOSE_ON_WRITE 0x00000040 /* Journal closes on writes */


/* what to mark indicator (ioctl parameter) */ 
#define MARK_DENTRY   101
#define MARK_FSET     102
#define MARK_CACHE    103
#define MARK_GETFL    104



struct readmount {
        int io_len;  /* this is IN & OUT: true length of str is returned */
        char *io_string;
};

/* modeled after setsockopt */
/* so if you have no /proc, oh well. */
/* for now it's all ints. We may grow this later for non-ints. */
struct psdev_opt {
        int optname;
        int optval;
};

struct lento_input {
        char *name;
        struct lento_vfs_context info;
};

struct lento_input_attr {
        char *name;
#if BITS_PER_LONG < 64
        __u32 dummy;    /* XXX on 64-bit platforms, this is not needed */
#endif
        __u32 valid;
        __u32 mode;
        __u32 uid;
        __u32 gid;
        __u64 size;
        __s64 atime;
        __s64 mtime;
        __s64 ctime;
        __u32 attr_flags;
        struct lento_vfs_context info;
};

struct lento_input_mode {
        char *name;
        __u32 mode;
        struct lento_vfs_context info;
};

struct lento_input_old_new {
        char *oldname;
        char *newname;
        struct lento_vfs_context info;
};

struct lento_input_dev {
        char *name;
        __u32 mode;
        __u32 major;
        __u32 minor;
        struct lento_vfs_context info;
};

struct lento_input_iopen {
        char *name;
#if BITS_PER_LONG < 64
        __u32 dummy;    /* XXX on 64-bit platforms, this is not needed */
#endif
        __u64 ino;
        __u32 generation;
        __u32 flags;
        __s32 fd;
};

struct lento_input_close {
        __u32 fd;
        struct lento_vfs_context info;
};

/* XXX should PRESTO_GET_* actually be of type _IOR, since we are reading? */
#define PRESTO_GETMOUNT         _IOW ('p',0x03, struct readmount *)
#define PRESTO_SETPID           _IOW ('p',0x04, struct readmount *)
#define PRESTO_CLOSE_JOURNALF   _IOW ('p',0x06, struct readmount *)
#define PRESTO_SET_FSETROOT     _IOW ('p',0x07, struct readmount *)
#define PRESTO_CLEAR_FSETROOT   _IOW ('p',0x08, struct readmount *)
#define PRESTO_SETOPT           _IOW ('p',0x09, struct psdev_opt *)
#define PRESTO_GETOPT           _IOW ('p',0x0a, struct psdev_opt *)
#define PRESTO_GET_KMLSIZE      _IOW ('p',0x0b, struct psdev_opt *)
#define PRESTO_GET_RECNO        _IOW ('p',0x0c, struct psdev_opt *)
#define PRESTO_VFS_SETATTR      _IOW ('p',0x10, struct lento_input_attr *)
#define PRESTO_VFS_CREATE       _IOW ('p',0x11, struct lento_input_mode *)
#define PRESTO_VFS_LINK         _IOW ('p',0x12, struct lento_input_old_new *)
#define PRESTO_VFS_UNLINK       _IOW ('p',0x13, struct lento_input *)
#define PRESTO_VFS_SYMLINK      _IOW ('p',0x14, struct lento_input_old_new *)
#define PRESTO_VFS_MKDIR        _IOW ('p',0x15, struct lento_input_mode *)
#define PRESTO_VFS_RMDIR        _IOW ('p',0x16, struct lento_input *)
#define PRESTO_VFS_MKNOD        _IOW ('p',0x17, struct lento_input_dev *)
#define PRESTO_VFS_RENAME       _IOW ('p',0x18, struct lento_input_old_new *)
#define PRESTO_VFS_CLOSE        _IOW ('p',0x1a, struct lento_input_close *)
#define PRESTO_VFS_IOPEN        _IOW ('p',0x1b, struct lento_input_iopen *)

#define PRESTO_MARK             _IOW ('p',0x20, struct lento_input_open *)
#define PRESTO_RELEASE_PERMIT   _IOW ('p',0x21, struct lento_input_open *)
#define PRESTO_CLEAR_ALL_FSETROOTS  _IOW ('p',0x22, struct readmount *)
#define PRESTO_BACKFETCH_LML    _IOW ('p',0x23, struct readmount *)
#define PRESTO_REINT            _IOW ('p',0x24, struct readmount *)
#define PRESTO_CANCEL_LML       _IOW ('p',0x25, struct readmount *)
#define PRESTO_RESET_FSET       _IOW ('p',0x26, struct readmount *)
#define PRESTO_COMPLETE_CLOSES  _IOW ('p',0x27, struct readmount *)

#define PRESTO_REINT_BEGIN      _IOW ('p',0x30, struct readmount *)
#define PRESTO_DO_REINT         _IOW ('p',0x31, struct readmount *)
#define PRESTO_REINT_END        _IOW ('p',0x32, struct readmount *)

#endif
