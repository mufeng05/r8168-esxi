/*
 *  generic_serial.h
 *
 *  Copyright (C) 1998 R.E.Wolff@BitWizard.nl
 *
 *  written for the SX serial driver.
 *     Contains the code that should be shared over all the serial drivers.
 *
 *  Version 0.1 -- December, 1998.
 */

#ifndef GENERIC_SERIAL_H
#define GENERIC_SERIAL_H




struct real_driver {
  void                    (*disable_tx_interrupts) (void *);
  void                    (*enable_tx_interrupts) (void *);
  void                    (*disable_rx_interrupts) (void *);
  void                    (*enable_rx_interrupts) (void *);
  int                     (*get_CD) (void *);
  void                    (*shutdown_port) (void*);
  int                     (*set_real_termios) (void*);
  int                     (*chars_in_buffer) (void*);
  void                    (*close) (void*);
  void                    (*hungup) (void*);
  void                    (*getserial) (void*, struct serial_struct *sp);
};




/* Flags */
/* Warning: serial.h defines some ASYNC_ flags, they say they are "only"
   used in serial.c, but they are also used in all other serial drivers. 
   Make sure they don't clash with these here... */
#define GS_TX_INTEN      0x00800000
#define GS_RX_INTEN      0x00400000
#define GS_ACTIVE        0x00200000



#define GS_TYPE_NORMAL   1
#define GS_TYPE_CALLOUT  2


#define GS_DEBUG_FLUSH   0x00000001
#define GS_DEBUG_BTR     0x00000002
#define GS_DEBUG_TERMIOS 0x00000004
#define GS_DEBUG_STUFF   0x00000008
#define GS_DEBUG_CLOSE   0x00000010
#define GS_DEBUG_FLOW    0x00000020

#endif
