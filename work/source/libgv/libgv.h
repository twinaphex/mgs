/*
 * [ LibGV ]
 * Memory Management,
 * Execution Unit Control,
 * & Common Math Library
 *
 * ver.METAL GEAR SOLID
 */
#ifndef INC_LIBGV_H
#define INC_LIBGV_H

#include "mgs_global.h"

/* GV Daemon (gvd.c) */
extern void GV_StartDaemon( void );

/* Actor Execution System (actor.c) */
extern void GV_ExecActorSystem( void );

/* String Hash Function (strcode.c) */
extern u_short GV_StrCode( char *string );

#endif /* INC_LIBGV_H */

/* -*- indent-tabs-mode: t; tab-width: 4; mode: c; -*- */
/* vim: set noet ts=4 sw=4 ft=c ff=dos fenc=euc-jp : */
