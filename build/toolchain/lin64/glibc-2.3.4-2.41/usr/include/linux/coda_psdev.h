#ifndef __CODA_PSDEV_H
#define __CODA_PSDEV_H

#define CODA_PSDEV_MAJOR 67
#define MAX_CODADEVS  5	   /* how many do we allow */

#define CODA_SUPER_MAGIC	0x73757245



/* messages between coda filesystem in kernel and Venus */
struct upc_req {
	struct list_head    uc_chain;
	caddr_t	            uc_data;
	u_short	            uc_flags;
	u_short             uc_inSize;  /* Size is at most 5000 bytes */
	u_short	            uc_outSize;
	u_short	            uc_opcode;  /* copied from data to save lookup */
	int		    uc_unique;
	wait_queue_head_t   uc_sleep;   /* process' wait queue */
	unsigned long       uc_posttime;
};

#define REQ_ASYNC  0x1
#define REQ_READ   0x2
#define REQ_WRITE  0x4
#define REQ_ABORT  0x8


/*
 * Statistics
 */
struct coda_upcallstats {
	int	ncalls;			/* client requests */
	int	nbadcalls;		/* upcall failures */
	int	reqs[CODA_NCALLS];	/* count of each request */
} ;


#endif
