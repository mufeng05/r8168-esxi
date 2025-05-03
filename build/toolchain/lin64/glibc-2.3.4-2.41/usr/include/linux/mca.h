/*
 * Header for Microchannel Architecture Bus
 * Written by Martin Kolinek, February 1996
 */

#ifndef _LINUX_MCA_H
#define _LINUX_MCA_H

/* Maximal number of MCA slots - actually, some machines have less, but
 * they all have sufficient number of POS registers to cover 8.
 */
#define MCA_MAX_SLOT_NR  8

/* MCA_NOTFOUND is an error condition.  The other two indicate
 * motherboard POS registers contain the adapter.  They might be
 * returned by the mca_find_adapter() function, and can be used as
 * arguments to mca_read_stored_pos().  I'm not going to allow direct
 * access to the motherboard registers until we run across an adapter
 * that requires it.  We don't know enough about them to know if it's
 * safe.
 *
 * See Documentation/mca.txt or one of the existing drivers for
 * more information.
 */
#define MCA_NOTFOUND	(-1)
#define MCA_INTEGSCSI	(MCA_MAX_SLOT_NR)
#define MCA_INTEGVIDEO	(MCA_MAX_SLOT_NR+1)
#define MCA_MOTHERBOARD (MCA_MAX_SLOT_NR+2)

/* Max number of adapters, including both slots and various integrated
 * things.
 */
#define MCA_NUMADAPTERS (MCA_MAX_SLOT_NR+3)

#endif /* _LINUX_MCA_H */
