/*
 * linux/include/linux/sunrpc/sched.h
 *
 * Scheduling primitives for kernel Sun RPC.
 *
 * Copyright (C) 1996, Olaf Kirch <okir@monad.swb.de>
 */

#ifndef _LINUX_SUNRPC_SCHED_H_
#define _LINUX_SUNRPC_SCHED_H_

#include <linux/sunrpc/types.h>

/*
 * Define this if you want to test the fast scheduler for async calls.
 * This is still experimental and may not work.
 */
#undef  CONFIG_RPC_FASTSCHED

/*
 * This is the actual RPC procedure call info.
 */
struct rpc_message {
	__u32			rpc_proc;	/* Procedure number */
	void *			rpc_argp;	/* Arguments */
	void *			rpc_resp;	/* Result */
	struct rpc_cred *	rpc_cred;	/* Credentials */
};



/*
 * RPC task flags
 */
#define RPC_TASK_ASYNC		0x0001		/* is an async task */
#define RPC_TASK_SWAPPER	0x0002		/* is swapping in/out */
#define RPC_TASK_SETUID		0x0004		/* is setuid process */
#define RPC_TASK_CHILD		0x0008		/* is child of other task */
#define RPC_CALL_REALUID	0x0010		/* try using real uid */
#define RPC_CALL_MAJORSEEN	0x0020		/* major timeout seen */
#define RPC_TASK_ROOTCREDS	0x0040		/* force root creds */
#define RPC_TASK_DYNAMIC	0x0080		/* task was kmalloc'ed */
#define RPC_TASK_KILLED		0x0100		/* task was killed */



#endif /* _LINUX_SUNRPC_SCHED_H_ */
