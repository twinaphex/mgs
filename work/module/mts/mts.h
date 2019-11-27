/*
 * New Multi-Task Scheduler for PSX
 * Global Incldue
 *
 * ref. beatmania APPEND 5thMIX
 *  1999.10.04 : work.5th/include/mts.h
 */
#ifndef INC_MTS_H
#define INC_MTS_H

#define NEWMTS 1

#ifndef MTS_NR_TASK
#ifndef NEWMTS
#define MTS_NR_TASK  64
#else  /* NEWMTS */
#define MTS_NR_TASK  12
#endif /* NEWMTS */
#endif /* MTS_NR_TASK */

#ifndef MTS_NR_INIT_TASK
#define MTS_NR_INIT_TASK  8 /* use V-Sync interrupt */
#endif

#ifndef MTS_MAX_SEMAPHORE
#define MTS_MAX_SEMAPHORE  32 /* semaphore num */
#endif

#define MTS_TASK_IDLE          (MTS_NR_TASK-1) /* pre-defined idle task */
#define MTS_TASK_SYSTEM        0               /* pre-defined system task */
#define MTS_TASK_INTR          (-1)
#define MTS_TASK_ANY           (-2)
#define MTS_TASK_INTR_RESETED  (-3)
#define MTS_TASK_INTR2         (-4)

#define MTS_SZ_MESSAGE  16

#define MTS_STANDARD_STACK_SIZE  (8*1024/sizeof(double))
#define MTS_STANDARD_STACK_TOP   (MTS_STANDARD_STACK_SIZE)

typedef unsigned long MTS_STACK;
#define STACK_AREA( name, size )    name[(size) / sizeof(MTS_STACK)]
#define STACK_BOTTOM( name, size )  ((char *)name + size)

extern void mts_boot( int tasknr, void (*procedure)(void), void *stack_pointer );
extern void mts_send( int dst, unsigned char *message );
/*extern void mts_isend( int dst );*/
extern int  mts_isend( int dst );
extern int  mts_receive( int src, unsigned char *message );
extern void mts_reschedule( void );

#if (0)
extern void mts_lock( void );
extern void mts_unlock( void );
#else
#define mts_lock()    SwEnterCriticalSection()
#define mts_unlock()  SwExitCriticalSection()
#endif

/* append by K.Uehara */

extern void mts_slp_tsk( void );
extern void mts_wup_tsk( int dst );

extern void mts_lock_sem( int no );
extern void mts_unlock_sem( int no );

extern long mts_get_current_task_id( void );
extern long mts_get_task_status( long id );

extern void mts_reset_interrupt_wait( long id );
extern void mts_reset_interrupt_overrun( void );

#ifdef DEBUG
extern void mts_set_stack_check( long task, void *stack_top, long stack_size );
extern void mts_print_process_status( void );
extern void mts_set_exception_func( void (*func)(void) );
extern void mts_print_memmap( void );
extern void mts_check_memmap( void );
extern void mts_get_use_stack_size( long *max, long *now, long *limit );
#else
#define mts_print_process_status()
#define mts_set_stack_check( a, b, c )
#define mts_set_exception_func( a )
#define mts_print_memmap()
#define mts_check_memmap()
#define mts_get_use_stack_size()
#endif /* DEBUG */

enum {
	MTS_TASK_DEAD,
	MTS_TASK_SENDING,
	MTS_TASK_RECEIVING,
	MTS_TASK_READY,
	MTS_TASK_SLEEPING,
	MTS_TASK_WAIT_VBL,
	MTS_PENDING
};

/* append end */

typedef struct {
	unsigned char count;
} MTS_MESSAGE_INTR_T;

extern int  mts_sta_tsk( int tasknr, void (*procedure)(void), void *stack_pointer );
extern void mts_ext_tsk( void );
extern void mts_send_msg( int dst, int data0, int data1 );
extern int  mts_recv_msg( int src, int *data0, int *data1 );

#ifdef DEBUG

#define mts_start_task( _tasknr, _procedure, _stack_pointer, _stack_size )\
{\
	mts_set_stack_check( _tasknr, _stack_pointer, _stack_size );\
	mts_sta_tsk( _tasknr, _procedure, _stack_pointer );\
}

extern void mts_boot_task( int tasknr, void (*procedure)(void), void *stack_pointer, long stack_size );

#else /* DEBUG */

#define mts_start_task( _tasknr, _procedure, _stack_pointer, _stack_size )\
           mts_sta_tsk( _tasknr, _procedure, _stack_pointer )

#define mts_boot_task( _tasknr, _procedure, _stack_pointer, _stack_size )\
             mts_boot( _tasknr, _procedure, _stack_pointer )

#endif /* DEBUG */

/* for UNIX signal stuff (cf. mts_lock()/mts_unlock()) */
extern void mts_set_interrupt_callback( void (*callback1)(int), void (*callback2)(int) );

/* for PSX V-Sync Interrupt */

extern void mts_init_vsync( void );
extern void mts_set_vsync_callback_func( int (*func)(void) );
extern void mts_set_vsync_task( void );
extern int  mts_wait_vbl( long count );

extern unsigned long mts_get_tick_count( void );

/* malloc */

extern void *mts_malloc( long size );
extern void  mts_free( void *ptr );
extern void  mts_free_all( long owner );
extern void  mts_set_malloc_limit( void *limit );
extern void  mts_change_memory_owner( void *ptr, long owner );

#define MTS_MALLOC_SEM_NO  0

#ifdef DEBUG

extern void mts_set_memory_fence( void *blocktop );
extern void mts_set_memory_fence_array( void *arraytop, long arraysize );
extern void *mts_memory_check( char *file, long line, void *ptr );

#define MTS_SET_MEMORY_FENCE( _blocktop )\
        mts_set_memory_fence( _blocktop )

#define MTS_SET_MEMORY_FENCE_ARRAY( _blocktop, _blocksize )\
        mts_set_memory_fence_array( _blocktop, _blocksize )

#define MTS_MEMORY_CHECK( _ptr )\
        mts_memory_check( __FILE__, __LINE__, _ptr )

#else

#define MTS_SET_MEMORY_FENCE( _blocktop )
#define MTS_SET_MEMORY_FENCE_ARRAY( _blocktop, _blocksize )
#define MTS_MEMORY_CHECK( _ptr )

#endif /* DEBUG */

/* Controller Service */

void mts_set_vsync_control_func( void (*func)(void) );

typedef struct {
	signed char channel;
	char button;
	signed char dx;
	signed char dy;
	long pos_x;
	long pos_y;
} MTS_MOUSE;

typedef struct {
	signed char channel;
	char flag;
	unsigned short button;
	unsigned char rx;
	unsigned char ry;
	unsigned char lx;
	unsigned char ly;
} MTS_PAD;

#define MTS_PAD_DIGITAL  1
#define MTS_PAD_ANAJOY   2
#define MTS_PAD_ANALOG   3

void  mts_init_controller( void );
void  mts_reset_mouse( MTS_MOUSE *mouse );
long  mts_get_mouse( MTS_MOUSE *mouse );
long  mts_get_pad( long channel, MTS_PAD *pad );
void *mts_get_controller_data( long channel );
unsigned short mts_read_pad( long channel );
void  mts_set_pad_vibration( long channel, long time );
void  mts_set_pad_vibration2( long channel, long value );
long  mts_get_pad_vibration_type( long channel );

void mts_reset_graph( void );

#define MTS_GetPad( _c, _p )  mts_get_pad( _c, _p )
#define PadInit( c )

/* Stream Service */

long set_stdout_stream( long stream );
void reset_stdout_stream( void );
void set_output_stream( long stream );

#ifndef __IN_MTS_NEW__

#define sio_output_stop()   set_output_stream( -1 );
#define sio_output_start()  set_output_stream( 0 );

#ifdef PSX
void fprintf( long stream, char *format, ... );
void printf( char *format, ... );  /* added for MGS */
void cprintf( char *format, ... ); /* added for MGS */
#endif /* PSX */

#endif /* __IN_MTS_NEW__ */

#ifdef PSX
#define stderr -1
#endif /* PSX */

/*---------------------------------------------------------------------------*/
#endif /* END OF FILE */
/*---------------------------------------------------------------------------*/
/* -*- indent-tabs-mode: t; tab-width: 4; mode: c; -*- */
/* vim: set noet ts=4 sw=4 ft=c ff=dos fenc=euc-jp : */
