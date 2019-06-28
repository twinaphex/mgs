/*
 *  METAL GEAR SOLID
 *  Startup Module
 */
#include "mgs_defs.h"
#include "mgs_types.h"
#include "mts.h"
#include "taskid.h"

/* find stack bottom */
#define bottom(s)  ((void *)(s) + sizeof(s))

//! manually inline if main() doesn't match as-is
static inline void START_GAME( void(*proc)(void) )
{
	static long32 Stack[512];
	
	mts_boot_task( MTSID_GAME, proc, bottom( Stack ), sizeof(Stack) );
}

static void MGS_Main( void )
{
	// TODO
}

void main( void )
{
	START_GAME( MGS_Main );
}

/* vim: set noet ts=4 sw=4 ff=dos fenc=euc-jp: */
