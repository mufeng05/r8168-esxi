/*
 * AGPGART module version 0.99
 * Copyright (C) 1999 Jeff Hartmann
 * Copyright (C) 1999 Precision Insight, Inc.
 * Copyright (C) 1999 Xi Graphics, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * JEFF HARTMANN, OR ANY OTHER CONTRIBUTORS BE LIABLE FOR ANY CLAIM, 
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR 
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE 
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef _AGP_BACKEND_H
#define _AGP_BACKEND_H 1

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#define AGPGART_VERSION_MAJOR 0
#define AGPGART_VERSION_MINOR 99

enum chipset_type {
	NOT_SUPPORTED,
	INTEL_GENERIC,
	INTEL_LX,
	INTEL_BX,
	INTEL_GX,
	INTEL_I810,
	INTEL_I815,
	INTEL_I840,
	INTEL_I850,
	VIA_GENERIC,
	VIA_VP3,
	VIA_MVP3,
	VIA_MVP4,
	VIA_APOLLO_PRO,
	VIA_APOLLO_KX133,
	VIA_APOLLO_KT133,
	SIS_GENERIC,
	AMD_GENERIC,
	AMD_IRONGATE,
	ALI_M1541,
	ALI_M1621,
	ALI_M1631,
	ALI_M1632,
	ALI_M1641,
	ALI_M1647,
	ALI_M1651,
	ALI_GENERIC,
	SVWRKS_HE,
	SVWRKS_LE,
	SVWRKS_GENERIC
};

typedef struct _agp_version {
	u16 major;
	u16 minor;
} agp_version;

typedef struct _agp_kern_info {
	agp_version version;
	struct pci_dev *device;
	enum chipset_type chipset;
	unsigned long mode;
	off_t aper_base;
	size_t aper_size;
	int max_memory;		/* In pages */
	int current_memory;
	int cant_use_aperture;
	unsigned long page_mask;
} agp_kern_info;

/* 
 * The agp_memory structure has information
 * about the block of agp memory allocated.
 * A caller may manipulate the next and prev
 * pointers to link each allocated item into
 * a list.  These pointers are ignored by the 
 * backend.  Everything else should never be
 * written to, but the caller may read any of
 * the items to detrimine the status of this
 * block of agp memory.
 * 
 */

typedef struct _agp_memory {
	int key;
	struct _agp_memory *next;
	struct _agp_memory *prev;
	size_t page_count;
	int num_scratch_pages;
	unsigned long *memory;
	off_t pg_start;
	u32 type;
	u32 physical;
	u8 is_bound;
	u8 is_flushed;
} agp_memory;

#define AGP_NORMAL_MEMORY 0


#endif				/* _AGP_BACKEND_H */
