/*
 * Internal SIO Driver for PSX
 * (interrupt version)
 *
 * ver."METAL GEAR SOLID"
 * ref."beatmania APPEND 5thMIX"
 *  work.5th/include/isio.h (Apr.06,1998)
 */
#ifndef __ISIO_H__
#define __ISIO_H__

#ifndef __ISIO_C__
#define EXTERN  extern
#else
#define EXTERN
#endif

EXTERN void          sio_putchar( unsigned char );
EXTERN unsigned char sio_getchar( void );
EXTERN int           sio_getchar2( void );
EXTERN int           sio_chkbuf( void );
EXTERN void          sio_flush( void );
EXTERN void          sio_puts( unsigned char * );
EXTERN int           sio_setup( int );
EXTERN void          sio_dump( unsigned char *, unsigned long );
EXTERN int           sio_get_dsr( void );
EXTERN int           sio_get_cts( void );

#endif /* END OF FILE */

/* -*- indent-tabs-mode: t; tab-width: 4; mode: c; -*- */
/* vim: set noet ts=4 sw=4 ft=c ff=dos fenc=euc-jp : */
