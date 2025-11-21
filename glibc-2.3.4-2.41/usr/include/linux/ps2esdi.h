#ifndef _PS2ESDI_H_
#define _PS2ESDI_H_

#define HDIO_GETGEO 0x0301

struct ps2esdi_geometry {
	unsigned char heads;
	unsigned char sectors;
	unsigned short cylinders;
	unsigned long start;
};

#endif /* _PS2ESDI_H_ */
