#ifndef __PRESTO_PSDEV_H
#define __PRESTO_PSDEV_H

#define MAX_PRESTODEV 16

#include <linux/version.h>


/* messages between presto filesystem in kernel and Venus */
#define REQ_READ   1
#define REQ_WRITE  2
#define REQ_ASYNC  4
#define REQ_DEAD   8

#endif
