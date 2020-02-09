/*
 * METAL GEAR SOLID
 * Startup Module
 */
#include "global.h"
#include <sys/types.h>
#include <libcd.h>
#include <libgte.h>
#include <libgpu.h>

// Needed for mts.h DEBUG-dependent definitions. If undefined:
// - mts_boot_task() will be replaced with a call to mts_boot()
// - mts_start_task() will not call mts_set_stack_check()
#ifndef DEBUG
#define DEBUG 1
#endif

#include "../../module/mts/mts.h"
#include "../../module/mts/taskid.h"
#include "../../module/sound/sound.h"
#include "../libgv/libgv.h"
#include "../libfs/libfs.h"
#include "../libdg/libdg.h"
#include "../libgcl/libgcl.h"
#include "../libhzd/libhzd.h"
#include "../libmc/libmc.h"
#include "../game/game.h"

/* find stack bottom */
#define bottom(s)  ((void *)(s) + sizeof(s))

/*---------------------------------------------------------------------------*/

static void MGS( void )
{
	RECT rect;
	static long32 SdStack[512]; /* 2KB */
	
	ResetGraph( 0 );
	SetGraphDebug( 0 );
	CdInit();
	SetDispMask( 0 );
	
	setRECT( &rect, 0, 0, 1024, 511 );
	ClearImage( &rect, 0, 0, 0 );
	
	DrawSync( 0 );
	SetDispMask( 1 );
	InitGeom();
	
	mts_init_vsync();
	mts_set_vsync_task();
	
	printf( "mem:" ); memcard_init();
	printf( "pad:" ); mts_init_controller();
	printf( "gv:"  ); GV_StartDaemon();
	printf( "fs:"  ); FS_StartDaemon();
	printf( "dg:"  ); DG_StartDaemon();
	printf( "gcl:" ); GCL_StartDaemon();
	printf( "hzd:" ); HZD_StartDaemon();
	
	printf( "sound:" );
	mts_start_task(
		MTSID_SOUND_MAIN,   /* task id    */
		SdMain,             /* procedure  */
		bottom(SdStack),    /* stack ptr  */
		sizeof(SdStack) );  /* stack size */
	
	while( !SdIntReady() ){
		mts_wait_vbl( 1 );
	}
	
	printf( "gm:" ); GM_StartDaemon();
	
	printf( "start\n" );
	
	while( 1 ){
		GV_ExecActorSystem();
	}
}

/*---------------------------------------------------------------------------*/

static inline void START_GAME( void(*proc)(void) )
{
	static long32 Stack[512]; /* 2KB */
	
	mts_boot_task(
		MTSID_GAME,         /* task id    */
		proc,               /* procedure  */
		bottom(Stack),      /* stack ptr  */
		sizeof(Stack) );    /* stack size */
}

/*---------------------------------------------------------------------------*/

int main()
{
#if (PSX_PILOT_DISC1)
	printf( "start MGS\n" );
#endif
	START_GAME( MGS );
}

/*---------------------------------------------------------------------------*
 * END OF FILE
 *---------------------------------------------------------------------------*/
/* -*- indent-tabs-mode: t; tab-width: 4; mode: c; -*- */
/* vim: set noet ts=4 sw=4 ft=c ff=dos fenc=euc-jp : */
