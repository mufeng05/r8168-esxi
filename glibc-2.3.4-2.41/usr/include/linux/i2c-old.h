#ifndef I2C_H
#define I2C_H

/*
 * linux i2c interface.  Works a little bit like the scsi subsystem.
 * There are:
 *
 *     i2c          the basic control module        (like scsi_mod)
 *     bus driver   a driver with a i2c bus         (hostadapter driver)
 *     chip driver  a driver for a chip connected
 *                  to a i2c bus                    (cdrom/hd driver)
 *
 * A device will be attached to one bus and one chip driver.  Every chip
 * driver gets a unique ID.
 *
 * A chip driver can provide a ioctl-like callback for the
 * communication with other parts of the kernel (not every i2c chip is
 * useful without other devices, a TV card tuner for example). 
 *
 * "i2c internal" parts of the structs: only the i2c module is allowed to
 * write to them, for others they are read-only.
 *
 */

#include <linux/version.h>

#define I2C_BUS_MAX       4    /* max # of bus drivers  */
#define I2C_DRIVER_MAX    8    /* max # of chip drivers */
#define I2C_DEVICE_MAX    8    /* max # if devices per bus/driver */

struct i2c_bus;
struct i2c_driver;
struct i2c_device;

#define I2C_DRIVERID_MSP3400    	 1
#define I2C_DRIVERID_TUNER      	 2
#define I2C_DRIVERID_VIDEOTEXT		 3
#define I2C_DRIVERID_VIDEODECODER	 4
#define I2C_DRIVERID_VIDEOENCODER	 5

#define I2C_BUSID_BT848		1	/* I2C bus on a BT848 */
#define I2C_BUSID_PARPORT	2	/* Bit banging on a parallel port */
#define I2C_BUSID_BUZ		3
#define I2C_BUSID_ZORAN		4
#define I2C_BUSID_CYBER2000	5

#endif /* I2C_H */
