/*
 *  rpcsock.h	Declarations for the RPC call interface.
 *
 *  Copyright (C) 1995, 1996 Olaf Kirch <okir@monad.swb.de>
 */


#ifndef _LINUX_RPCSOCK_H
#define _LINUX_RPCSOCK_H

/*
 * The rpcsock code maintains an estimate on the maximum number of out-
 * standing RPC requests, using the congestion avoidance implemented in
 * 44BSD. This is basically the Van Jacobson slow start algorithm: If a
 * retransmit occurs, the congestion window is halved; otherwise, it is
 * incremented by 1/cwnd when a reply is received and a full number of
 * requests are outstanding.
 *
 * Upper procedures may check whether a request would block waiting for
 * a free RPC slot by using the RPC_CONGESTED() macro.
 *
 * Note: on machines with low memory we should probably use a smaller
 * MAXREQS value: At 32 outstanding reqs with 8 megs of RAM, fragment
 * reassembly will frequently run out of memory.
 */
#define RPC_MAXREQS		32
#define RPC_CWNDSCALE		256
#define RPC_MAXCWND		(RPC_MAXREQS * RPC_CWNDSCALE)
/* #define RPC_INITCWND		(RPC_MAXCWND / 2) */
#define RPC_INITCWND		RPC_CWNDSCALE
#define RPC_CONGESTED(rsock)	((rsock)->cong >= (rsock)->cwnd)

/* RPC reply header size: xid, direction, status, accept_status (verifier
 * size computed separately)
 */
#define RPC_HDRSIZE		(4 * 4)

/*
 * This describes a timeout strategy
 */
struct rpc_timeout {
	unsigned long		to_initval,
				to_maxval,
				to_increment;
	int			to_retries;
	char			to_exponential;
};

/*
 * This describes a complete RPC request
 */
struct rpc_ioreq {
	struct rpc_wait *	rq_slot;
	struct sockaddr	*	rq_addr;
	int			rq_alen;
	struct iovec		rq_svec[UIO_FASTIOV];
	unsigned int		rq_snr;
	unsigned long		rq_slen;
	struct iovec		rq_rvec[UIO_FASTIOV];
	unsigned int		rq_rnr;
	unsigned long		rq_rlen;
};

/*
 * This is the callback handler for async RPC.
 */
struct rpc_wait;
typedef void	(*rpc_callback_fn_t)(int, struct rpc_wait *, void *);

#endif /* _LINUX_RPCSOCK_H */
