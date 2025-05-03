#ifndef _ASMi386_PARAM_H
#define _ASMi386_PARAM_H

#include <unistd.h>

#ifndef HZ
#define HZ sysconf(_SC_CLK_TCK)
#endif

#define EXEC_PAGESIZE	4096

#ifndef NGROUPS
#define NGROUPS		32
#endif

#ifndef NOGROUP
#define NOGROUP		(-1)
#endif

#define MAXHOSTNAMELEN	64	/* max length of hostname */

#endif
