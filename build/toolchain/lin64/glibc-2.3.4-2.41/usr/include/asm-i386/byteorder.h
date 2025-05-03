#ifndef _I386_BYTEORDER_H
#define _I386_BYTEORDER_H

#include <asm/types.h>

#warning using private kernel header; include <endian.h> instead!
#ifdef __GNUC__

/* For avoiding bswap on i386 */

static __inline__ __const__ __u32 ___arch__swab32(__u32 x)
{
	__asm__("bswap %0" : "=r" (x) : "0" (x));
	return x;
}

static __inline__ __const__ __u16 ___arch__swab16(__u16 x)
{
	__asm__("xchgb %b0,%h0"		/* swap bytes		*/ \
		: "=q" (x) \
		:  "0" (x)); \
		return x;
}

#define __arch__swab32(x) ___arch__swab32(x)
#define __arch__swab16(x) ___arch__swab16(x)

#if !defined(__STRICT_ANSI__) || defined(__KERNEL__)
#  define __BYTEORDER_HAS_U64__
#  define __SWAB_64_THRU_32__
#endif

#endif /* __GNUC__ */

#include <linux/byteorder/little_endian.h>

#endif /* _I386_BYTEORDER_H */
