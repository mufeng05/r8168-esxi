/*
 * Private header file for the (dumb) serial driver
 *
 * Copyright (C) 1997 by Theodore Ts'o.
 * 
 * Redistribution of this file is permitted under the terms of the GNU 
 * Public License (GPL)
 */

#ifndef _LINUX_SERIALP_H
#define _LINUX_SERIALP_H

/*
 * This is our internal structure for each serial port's state.
 * 
 * Many fields are paralleled by the structure used by the serial_struct
 * structure.
 *
 * For definitions of the flags field, see tty.h
 */

#include <linux/config.h>
#include <linux/termios.h>
#include <linux/circ_buf.h>
#include <linux/wait.h>


#define CONFIGURED_SERIAL_PORT(info) ((info)->port || ((info)->iomem_base))

#define SERIAL_MAGIC 0x5301
#define SSTATE_MAGIC 0x5302

/*
 * Events are used to schedule things to happen at timer-interrupt
 * time, instead of at rs interrupt time.
 */
#define RS_EVENT_WRITE_WAKEUP	0

struct pci_board_inst {
	struct pci_board	board;
	struct pci_dev		*dev;
};

#ifndef PCI_ANY_ID
#define PCI_ANY_ID (~0)
#endif

#define SPCI_FL_BASE_MASK	0x0007
#define SPCI_FL_BASE0	0x0000
#define SPCI_FL_BASE1	0x0001
#define SPCI_FL_BASE2	0x0002
#define SPCI_FL_BASE3	0x0003
#define SPCI_FL_BASE4	0x0004
#define SPCI_FL_GET_BASE(x)	(x & SPCI_FL_BASE_MASK)

#define SPCI_FL_IRQ_MASK       (0x0007 << 4)
#define SPCI_FL_IRQBASE0       (0x0000 << 4)
#define SPCI_FL_IRQBASE1       (0x0001 << 4)
#define SPCI_FL_IRQBASE2       (0x0002 << 4)
#define SPCI_FL_IRQBASE3       (0x0003 << 4)
#define SPCI_FL_IRQBASE4       (0x0004 << 4)
#define SPCI_FL_GET_IRQBASE(x)        ((x & SPCI_FL_IRQ_MASK) >> 4)

/* Use successive BARs (PCI base address registers), 
   else use offset into some specified BAR */
#define SPCI_FL_BASE_TABLE	0x0100

/* Use successive entries in the irq resource table */
#define SPCI_FL_IRQ_TABLE	0x0200

/* Use the irq resource table instead of dev->irq */
#define SPCI_FL_IRQRESOURCE	0x0400

/* Use the Base address register size to cap number of ports */
#define SPCI_FL_REGION_SZ_CAP	0x0800

/* Do not use irq sharing for this device */
#define SPCI_FL_NO_SHIRQ	0x1000

/* This is a PNP device */
#define SPCI_FL_ISPNP		0x2000

#define SPCI_FL_PNPDEFAULT	(SPCI_FL_IRQRESOURCE|SPCI_FL_ISPNP)

#endif /* _LINUX_SERIAL_H */
