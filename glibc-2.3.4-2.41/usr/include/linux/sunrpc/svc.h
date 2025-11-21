/*
 * linux/include/linux/sunrpc/svc.h
 *
 * RPC server declarations.
 *
 * Copyright (C) 1995, 1996 Olaf Kirch <okir@monad.swb.de>
 */


#ifndef SUNRPC_SVC_H
#define SUNRPC_SVC_H

#include <linux/in.h>
#include <linux/sunrpc/types.h>
#include <linux/sunrpc/xdr.h>
#include <linux/sunrpc/svcauth.h>

/*
 * Maximum payload size supported by a kernel RPC server.
 * This is use to determine the max number of pages nfsd is
 * willing to return in a single READ operation.
 */
#define RPCSVC_MAXPAYLOAD	16384u

/*
 * Buffer to store RPC requests or replies in.
 * Each server thread has one of these beasts.
 *
 * Area points to the allocated memory chunk currently owned by the
 * buffer. Base points to the buffer containing the request, which is
 * different from area when directly reading from an sk_buff. buf is
 * the current read/write position while processing an RPC request.
 *
 * The array of iovecs can hold additional data that the server process
 * may not want to copy into the RPC reply buffer, but pass to the 
 * network sendmsg routines directly. The prime candidate for this
 * will of course be NFS READ operations, but one might also want to
 * do something about READLINK and READDIR. It might be worthwhile
 * to implement some generic readdir cache in the VFS layer...
 *
 * On the receiving end of the RPC server, the iovec may be used to hold
 * the list of IP fragments once we get to process fragmented UDP
 * datagrams directly.
 */
#define RPCSVC_MAXIOV		((RPCSVC_MAXPAYLOAD+PAGE_SIZE-1)/PAGE_SIZE + 1)
struct svc_buf {
	u32 *			area;	/* allocated memory */
	u32 *			base;	/* base of RPC datagram */
	int			buflen;	/* total length of buffer */
	u32 *			buf;	/* read/write pointer */
	int			len;	/* current end of buffer */

	/* iovec for zero-copy NFS READs */
	struct iovec		iov[RPCSVC_MAXIOV];
	int			nriov;
};
#define svc_getlong(argp, val)	{ (val) = *(argp)->buf++; (argp)->len--; }
#define svc_putlong(resp, val)	{ *(resp)->buf++ = (val); (resp)->len++; }


/*
 * RPC procedure info
 */
typedef int	(*svc_procfunc)(struct svc_rqst *, void *argp, void *resp);
struct svc_procedure {
	svc_procfunc		pc_func;	/* process the request */
	kxdrproc_t		pc_decode;	/* XDR decode args */
	kxdrproc_t		pc_encode;	/* XDR encode result */
	kxdrproc_t		pc_release;	/* XDR free result */
	unsigned int		pc_argsize;	/* argument struct size */
	unsigned int		pc_ressize;	/* result struct size */
	unsigned int		pc_count;	/* call count */
	unsigned int		pc_cachetype;	/* cache info (NFS) */
};


#endif /* SUNRPC_SVC_H */
