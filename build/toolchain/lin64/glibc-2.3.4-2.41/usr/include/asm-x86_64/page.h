#ifndef _X86_64_PAGE_H
#define _X86_64_PAGE_H

/* PAGE_SHIFT determines the page size */
#define PAGE_SHIFT	12
#ifdef __ASSEMBLY__
#define PAGE_SIZE	(0x1 << PAGE_SHIFT)
#else
#define PAGE_SIZE	(1UL << PAGE_SHIFT)
#endif
#define PAGE_MASK	(~(PAGE_SIZE-1))
#define THREAD_SIZE (2*PAGE_SIZE)
#define CURRENT_MASK (~(THREAD_SIZE-1))


#endif /* _X86_64_PAGE_H */
