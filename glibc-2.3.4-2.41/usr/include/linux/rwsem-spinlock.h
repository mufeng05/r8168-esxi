/* rwsem-spinlock.h: fallback C implementation
 *
 * Copyright (c) 2001   David Howells (dhowells@redhat.com).
 * - Derived partially from ideas by Andrea Arcangeli <andrea@suse.de>
 * - Derived also from comments by Linus
 */

#ifndef _LINUX_RWSEM_SPINLOCK_H
#define _LINUX_RWSEM_SPINLOCK_H

#ifndef _LINUX_RWSEM_H
#error please dont include linux/rwsem-spinlock.h directly, use linux/rwsem.h instead
#endif

#include <linux/spinlock.h>
#include <linux/list.h>

#endif /* _LINUX_RWSEM_SPINLOCK_H */
