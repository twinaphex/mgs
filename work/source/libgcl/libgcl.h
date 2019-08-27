/*
 * Game Command Language
 * Script Interpreter Library
 * for METAL GEAR SOLID
 */
#ifndef INC_LIBGCL_H
#define INC_LIBGCL_H

#include "mgs_global.h"

/*---------------------------------------------------------------------------*
 * GCL Structures (ref.SLPM86249:vr_fms01.bin, MGS4)
 *---------------------------------------------------------------------------*/

typedef int GCL_COMMANDFUNC(char *);

typedef struct {
	long32 id;
	GCL_COMMANDFUNC *func;
} GCL_COMMANDLIST;

typedef struct _gcl_commanddef {
	struct _gcl_commanddef *next;
	long32 n_commlist;
	GCL_COMMANDLIST *commlist;
} GCL_COMMANDDEF;

typedef struct {
	u_short argc;
	long32 *argv;
} GCL_ARGS;

/*---------------------------------------------------------------------------*
 * Endianness Conversion (ref.SLPM86249:vr_fms01.bin)
 *---------------------------------------------------------------------------*/

/****** MEMLEAK START ******/

static inline long GCL_GetLong( char *ptr )
{
	unsigned char *p;
	p = ( unsigned char * )ptr;
	return ( p[ 0 ] << 24 ) | ( p[ 1 ] << 16 ) | ( p[ 2 ] << 8 ) | ( p[ 3 ] );
}

static inline long GCL_GetShort( char *ptr )
{
	unsigned char *p;
	p = ( unsigned char * )ptr;
	return ( signed short )( ( p[ 0 ] << 8 ) | ( p[ 1 ] ) );
}

static inline char GCL_GetByte( char *ptr )
{
	return *ptr;
}

/****** MEMLEAK END ******/

/*---------------------------------------------------------------------------*
 * END OF FILE
 *---------------------------------------------------------------------------*/
#endif // INC_LIBGCL_H

/* -*- indent-tabs-mode: t; tab-width: 4; mode: c; -*- */
/* vim: set noet ts=4 sw=4 ft=c ff=dos fenc=euc-jp : */
