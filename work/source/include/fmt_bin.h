/*
 * Overlay Format Definitions
 */
#ifndef INC_FMT_BIN_H
#define INC_FMT_BIN_H

#include "mgs_global.h"

typedef struct tBIN_GCL_ENTRY {
	u_long32 strcode; // only uses the lower 16 bits
	u_long32 addr;    // function pointer (?)
} BIN_GCL_ENTRY;

#endif // INC_FMT_BIN_H

/* vim: set noet ts=4 sw=4 ff=dos fenc=euc-jp: */
