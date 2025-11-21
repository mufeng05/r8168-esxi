#ifndef __LINUX_NETFILTER_H
#define __LINUX_NETFILTER_H

/* Responses from hook functions. */
#define NF_DROP 0
#define NF_ACCEPT 1
#define NF_STOLEN 2
#define NF_QUEUE 3
#define NF_REPEAT 4
#define NF_MAX_VERDICT NF_REPEAT

/* Generic cache responses from hook functions. */
#define NFC_ALTERED 0x8000
#define NFC_UNKNOWN 0x4000



#endif /*__LINUX_NETFILTER_H*/
