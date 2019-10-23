/*
 * METAL GEAR SOLID
 * Startup Module
 */
#include <sys/types.h>
#include <libcd.h>
#include <libgte.h>
#include <libgpu.h>

#include "mgs_global.h"
#include "mgs_libs.h"

/* find stack bottom */
#define bottom(s)  ((void *)(s) + sizeof(s))

static void Main( void )
{
	RECT rect;
	static long32 SdStack[512];
	
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
	
	printf( "mem:" );
	MC_StartDaemon();
	
	printf( "pad:" );
	mts_init_controller();
	
	printf( "gv:" );
	GV_StartDaemon();
	
	printf( "fs:" );
	FS_StartDaemon();
	
	printf( "dg:" );
	DG_StartDaemon();
	
	printf( "gcl:" );
	GCL_StartDaemon();
	
	printf( "hzd:" );
	HZD_StartDaemon();
	
	printf( "sound:" );
	mts_start_task(
		MTSID_SOUND_MAIN,   /* task id    */
		SdMain,             /* procedure  */
		bottom(SdStack),    /* stack ptr  */
		sizeof(SdStack) );  /* stack size */
	
	while ( !SdIntReady() ){
		mts_wait_vbl( 1 );
	}
	
	printf( "gm:" );
	GM_StartDaemon();
	
	printf( "start\n" );
	
	while (1){
		GV_ExecActorSystem();
	}
}

int main()
{
	static long32 Stack[512];
	
#if ( MGS_PILOT_DISC1 )
	printf( "start MGS\n" );
#endif
	mts_boot_task(
		MTSID_GAME,         /* task id    */
		Main,               /* procedure  */
		bottom(Stack),      /* stack ptr  */
		sizeof(Stack) );    /* stack size */
}

/* -*- indent-tabs-mode: t; tab-width: 4; mode: c; -*- */
/* vim: set noet ts=4 sw=4 ft=c ff=dos fenc=euc-jp : */
