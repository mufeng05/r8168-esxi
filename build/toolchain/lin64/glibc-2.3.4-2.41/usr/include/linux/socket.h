#ifndef _LINUX_SOCKET_H
#define _LINUX_SOCKET_H

#if defined(__KERNEL__) || !defined(__GLIBC__) || (__GLIBC__ < 2)

#include <asm/socket.h>			/* arch-dependent defines	*/
#include <linux/sockios.h>		/* the SIOCxxx I/O controls	*/
#include <linux/uio.h>			/* iovec support		*/
#include <linux/types.h>		/* pid_t			*/

typedef unsigned short	sa_family_t;

/*
 *	1003.1g requires sa_family_t and that sa_data is char.
 */
 
struct sockaddr {
	sa_family_t	sa_family;	/* address family, AF_xxx	*/
	char		sa_data[14];	/* 14 bytes of protocol address	*/
};

struct linger {
	int		l_onoff;	/* Linger active		*/
	int		l_linger;	/* How long to linger for	*/
};

/*
 *	As we do 4.4BSD message passing we use a 4.4BSD message passing
 *	system, not 4.3. Thus msg_accrights(len) are now missing. They
 *	belong in an obscure libc emulation or the bin.
 */
 
struct msghdr {
	void	*	msg_name;	/* Socket name			*/
	int		msg_namelen;	/* Length of name		*/
	struct iovec *	msg_iov;	/* Data blocks			*/
	__kernel_size_t	msg_iovlen;	/* Number of blocks		*/
	void 	*	msg_control;	/* Per protocol magic (eg BSD file descriptor passing) */
	__kernel_size_t	msg_controllen;	/* Length of cmsg list */
	unsigned	msg_flags;
};

/*
 *	POSIX 1003.1g - ancillary data object information
 *	Ancillary data consits of a sequence of pairs of
 *	(cmsghdr, cmsg_data[])
 */

struct cmsghdr {
	__kernel_size_t	cmsg_len;	/* data byte count, including hdr */
        int		cmsg_level;	/* originating protocol */
        int		cmsg_type;	/* protocol-specific type */
};

/*
 *	Ancilliary data object information MACROS
 *	Table 5-14 of POSIX 1003.1g
 */

#define __CMSG_NXTHDR(ctl, len, cmsg) __cmsg_nxthdr((ctl),(len),(cmsg))
#define CMSG_NXTHDR(mhdr, cmsg) cmsg_nxthdr((mhdr), (cmsg))

#define CMSG_ALIGN(len) ( ((len)+sizeof(long)-1) & ~(sizeof(long)-1) )

#define CMSG_DATA(cmsg)	((void *)((char *)(cmsg) + CMSG_ALIGN(sizeof(struct cmsghdr))))
#define CMSG_SPACE(len) (CMSG_ALIGN(sizeof(struct cmsghdr)) + CMSG_ALIGN(len))
#define CMSG_LEN(len) (CMSG_ALIGN(sizeof(struct cmsghdr)) + (len))

#define __CMSG_FIRSTHDR(ctl,len) ((len) >= sizeof(struct cmsghdr) ? \
				  (struct cmsghdr *)(ctl) : \
				  (struct cmsghdr *)NULL)
#define CMSG_FIRSTHDR(msg)	__CMSG_FIRSTHDR((msg)->msg_control, (msg)->msg_controllen)

/*
 *	This mess will go away with glibc
 */
 
#if  defined(__GNUC__) 
#define __KINLINE static __inline__
#elif defined(__cplusplus)
#define __KINLINE static inline
#endif

/*
 *	Get the next cmsg header
 *
 *	PLEASE, do not touch this function. If you think, that it is
 *	incorrect, grep kernel sources and think about consequences
 *	before trying to improve it.
 *
 *	Now it always returns valid, not truncated ancillary object
 *	HEADER. But caller still MUST check, that cmsg->cmsg_len is
 *	inside range, given by msg->msg_controllen before using
 *	ansillary object DATA.				--ANK (980731)
 */
 
__KINLINE struct cmsghdr * __cmsg_nxthdr(void *__ctl, __kernel_size_t __size,
					       struct cmsghdr *__cmsg)
{
	struct cmsghdr * __ptr;

	__ptr = (struct cmsghdr*)(((unsigned char *) __cmsg) +  CMSG_ALIGN(__cmsg->cmsg_len));
	if ((unsigned long)((char*)(__ptr+1) - (char *) __ctl) > __size)
		return (struct cmsghdr *)0;

	return __ptr;
}

__KINLINE struct cmsghdr * cmsg_nxthdr (struct msghdr *__msg, struct cmsghdr *__cmsg)
{
	return __cmsg_nxthdr(__msg->msg_control, __msg->msg_controllen, __cmsg);
}

/* "Socket"-level control message types: */

#define	SCM_RIGHTS	0x01		/* rw: access rights (array of int) */
#define SCM_CREDENTIALS 0x02		/* rw: struct ucred		*/
#define SCM_CONNECT	0x03		/* rw: struct scm_connect	*/

struct ucred {
	__u32	pid;
	__u32	uid;
	__u32	gid;
};

/* Supported address families. */
#define AF_UNSPEC	0
#define AF_UNIX		1	/* Unix domain sockets 		*/
#define AF_LOCAL	1	/* POSIX name for AF_UNIX	*/
#define AF_INET		2	/* Internet IP Protocol 	*/
#define AF_AX25		3	/* Amateur Radio AX.25 		*/
#define AF_IPX		4	/* Novell IPX 			*/
#define AF_APPLETALK	5	/* AppleTalk DDP 		*/
#define AF_NETROM	6	/* Amateur Radio NET/ROM 	*/
#define AF_BRIDGE	7	/* Multiprotocol bridge 	*/
#define AF_ATMPVC	8	/* ATM PVCs			*/
#define AF_X25		9	/* Reserved for X.25 project 	*/
#define AF_INET6	10	/* IP version 6			*/
#define AF_ROSE		11	/* Amateur Radio X.25 PLP	*/
#define AF_DECnet	12	/* Reserved for DECnet project	*/
#define AF_NETBEUI	13	/* Reserved for 802.2LLC project*/
#define AF_SECURITY	14	/* Security callback pseudo AF */
#define AF_KEY		15      /* PF_KEY key management API */
#define AF_NETLINK	16
#define AF_ROUTE	AF_NETLINK /* Alias to emulate 4.4BSD */
#define AF_PACKET	17	/* Packet family		*/
#define AF_ASH		18	/* Ash				*/
#define AF_ECONET	19	/* Acorn Econet			*/
#define AF_ATMSVC	20	/* ATM SVCs			*/
#define AF_SNA		22	/* Linux SNA Project (nutters!) */
#define AF_IRDA		23	/* IRDA sockets			*/
#define AF_PPPOX	24	/* PPPoX sockets		*/
#define AF_WANPIPE	25	/* Wanpipe API Sockets */
#define AF_LLC		26	/* Linux LLC			*/
#define AF_BLUETOOTH	31	/* Bluetooth sockets 		*/
#define AF_MAX		32	/* For now.. */

/* Protocol families, same as address families. */
#define PF_UNSPEC	AF_UNSPEC
#define PF_UNIX		AF_UNIX
#define PF_LOCAL	AF_LOCAL
#define PF_INET		AF_INET
#define PF_AX25		AF_AX25
#define PF_IPX		AF_IPX
#define PF_APPLETALK	AF_APPLETALK
#define	PF_NETROM	AF_NETROM
#define PF_BRIDGE	AF_BRIDGE
#define PF_ATMPVC	AF_ATMPVC
#define PF_X25		AF_X25
#define PF_INET6	AF_INET6
#define PF_ROSE		AF_ROSE
#define PF_DECnet	AF_DECnet
#define PF_NETBEUI	AF_NETBEUI
#define PF_SECURITY	AF_SECURITY
#define PF_KEY		AF_KEY
#define PF_NETLINK	AF_NETLINK
#define PF_ROUTE	AF_ROUTE
#define PF_PACKET	AF_PACKET
#define PF_ASH		AF_ASH
#define PF_ECONET	AF_ECONET
#define PF_ATMSVC	AF_ATMSVC
#define PF_SNA		AF_SNA
#define PF_IRDA		AF_IRDA
#define PF_PPPOX	AF_PPPOX
#define PF_WANPIPE	AF_WANPIPE
#define PF_LLC		AF_LLC
#define PF_BLUETOOTH	AF_BLUETOOTH
#define PF_MAX		AF_MAX

/* Maximum queue length specifiable by listen.  */
#define SOMAXCONN	128

/* Flags we can use with send/ and recv. 
   Added those for 1003.1g not all are supported yet
 */
 
#define MSG_OOB		1
#define MSG_PEEK	2
#define MSG_DONTROUTE	4
#define MSG_TRYHARD     4       /* Synonym for MSG_DONTROUTE for DECnet */
#define MSG_CTRUNC	8
#define MSG_PROBE	0x10	/* Do not send. Only probe path f.e. for MTU */
#define MSG_TRUNC	0x20
#define MSG_DONTWAIT	0x40	/* Nonblocking io		 */
#define MSG_EOR         0x80	/* End of record */
#define MSG_WAITALL	0x100	/* Wait for a full request */
#define MSG_FIN         0x200
#define MSG_SYN		0x400
#define MSG_CONFIRM	0x800	/* Confirm path validity */
#define MSG_RST		0x1000
#define MSG_ERRQUEUE	0x2000	/* Fetch message from error queue */
#define MSG_NOSIGNAL	0x4000	/* Do not generate SIGPIPE */
#define MSG_MORE	0x8000	/* Sender will send more */

#define MSG_EOF         MSG_FIN


/* Setsockoptions(2) level. Thanks to BSD these must match IPPROTO_xxx */
#define SOL_IP		0
/* #define SOL_ICMP	1	No-no-no! Due to Linux :-) we cannot use SOL_ICMP=1 */
#define SOL_TCP		6
#define SOL_UDP		17
#define SOL_IPV6	41
#define SOL_ICMPV6	58
#define SOL_SCTP	132
#define SOL_RAW		255
#define SOL_IPX		256
#define SOL_AX25	257
#define SOL_ATALK	258
#define SOL_NETROM	259
#define SOL_ROSE	260
#define SOL_DECNET	261
#define	SOL_X25		262
#define SOL_PACKET	263
#define SOL_ATM		264	/* ATM layer (cell level) */
#define SOL_AAL		265	/* ATM Adaption Layer (packet level) */
#define SOL_IRDA        266
#define SOL_NETBEUI	267
#define SOL_LLC		268

/* IPX options */
#define IPX_TYPE	1

#endif /* not kernel and not glibc */
#endif /* _LINUX_SOCKET_H */
