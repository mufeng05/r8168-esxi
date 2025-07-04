/*
 * linux/include/linux/sunrpc/debug.h
 *
 * Debugging support for sunrpc module
 *
 * Copyright (C) 1996, Olaf Kirch <okir@monad.swb.de>
 */

#ifndef _LINUX_SUNRPC_DEBUG_H_
#define _LINUX_SUNRPC_DEBUG_H_

#include <linux/config.h>

/*
 * Enable RPC debugging/profiling.
 */
#ifdef CONFIG_SYSCTL
#define  RPC_DEBUG
#endif
/* #define  RPC_PROFILE */

/*
 * RPC debug facilities
 */
#define RPCDBG_XPRT		0x0001
#define RPCDBG_CALL		0x0002
#define RPCDBG_DEBUG		0x0004
#define RPCDBG_NFS		0x0008
#define RPCDBG_AUTH		0x0010
#define RPCDBG_PMAP		0x0020
#define RPCDBG_SCHED		0x0040
#define RPCDBG_SVCSOCK		0x0100
#define RPCDBG_SVCDSP		0x0200
#define RPCDBG_MISC		0x0400
#define RPCDBG_ALL		0x7fff

/*
 * Declarations for the sysctl debug interface, which allows to read or
 * change the debug flags for rpc, nfs, nfsd, and lockd. Since the sunrpc
 * module currently registers its sysctl table dynamically, the sysctl path
 * for module FOO is <CTL_SUNRPC, CTL_FOODEBUG>.
 */
#define CTL_SUNRPC	7249	/* arbitrary and hopefully unused */

enum {
	CTL_RPCDEBUG = 1,
	CTL_NFSDEBUG,
	CTL_NFSDDEBUG,
	CTL_NLMDEBUG,
};

#endif /* _LINUX_SUNRPC_DEBUG_H_ */
