/*
 * [ LibGV ]
 * Memory Management,
 * Execution Unit Control,
 * & Common Math Library
 */
#ifndef INC_LIBGV_H
#define INC_LIBGV_H

#include "global.h"
#include <sys/types.h>

/*---------------------------------------------------------------------------*
 * Prototypes
 *---------------------------------------------------------------------------*/

/* GV Daemon (gvd.c) */
extern void GV_StartDaemon( void );

/* Actor System (actor.c) */
extern void GV_ExecActorSystem( void );

/* String Hash Function (strcode.c) */
extern u_short GV_StrCode( char *string );

/*---------------------------------------------------------------------------*/
#endif /* END OF FILE */
/*---------------------------------------------------------------------------*/
/* -*- indent-tabs-mode: t; tab-width: 4; mode: c; -*- */
/* vim: set noet ts=4 sw=4 ft=c ff=dos fenc=euc-jp : */
