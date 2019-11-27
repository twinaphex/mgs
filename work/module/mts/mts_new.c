/*
 * New Multi-Task Scheduler for PSX
 */
#include "global.h"
#include "mts.h"
#include "taskid.h"

/*---------------------------------------------------------------------------*
 * Build Config Defines
 *---------------------------------------------------------------------------*/
#if (PSX_PILOT_DISC1)
#define MTS_BUILD_DATE "Mar 17 1998"
#define MTS_BUILD_TIME "20:53:30"
/*-----------------------------------*/
#elif (PSX_DEMO_JPN)    \
||    (PSX_PILOT_DISC2) \
||    (PSX_DEMO_USA)    \
||    (PSX_DEMO_PAL1)
#define MTS_BUILD_DATE "Jun 13 1998"
#define MTS_BUILD_TIME "15:05:16"
/*-----------------------------------*/
#elif (PSX_JPN)      \
||    (PSX_USA_v10)  \
||    (PSX_USA_v11)  \
||    (PSX_PAL_EN)   \
||    (PSX_PAL_GR)   \
||    (PSX_PAL_FR)   \
||    (PSX_INTEGRAL) \
||    (PSX_VR_JPN)
#define MTS_BUILD_DATE "Jul 11 1998"
#define MTS_BUILD_TIME "22:16:33"
/*-----------------------------------*/
#elif (PSX_DEMO_PAL2)
#define MTS_BUILD_DATE "Nov 12 1998"
#define MTS_BUILD_TIME "18:51:44"
/*-----------------------------------*/
#elif (PSX_PAL_IT)     \
||    (PSX_PAL_SP_v10) \
||    (PSX_PAL_SP_v11) \
||    (PSX_VR_USA)     \
||    (PSX_VR_PAL)
#define MTS_BUILD_DATE "Nov 12 1998"
#define MTS_BUILD_TIME "20:00:47"
/*-----------------------------------*/
#elif (PSX_VR_USA_DEMO)
#define MTS_BUILD_DATE "Jun 11 1999"
#define MTS_BUILD_TIME "10:13:47"
/*-----------------------------------*/
#elif (PSX_MGS4_FR) \
||    (PSX_MGS4_GR) \
||    (PSX_MGS4_IT) \
||    (PSX_MGS4_JP) \
||    (PSX_MGS4_SP) \
||    (PSX_MGS4_US)
#define MTS_BUILD_DATE "Aug 21 2007"
#define MTS_BUILD_TIME "21:28:42"
/*-----------------------------------*/
#else /* NEW BUILD */
#define MTS_BUILD_DATE __DATE__
#define MTS_BUILD_TIME __TIME__
#endif

/*---------------------------------------------------------------------------*
 * END OF FILE
 *---------------------------------------------------------------------------*/
/* -*- indent-tabs-mode: t; tab-width: 4; mode: c; -*- */
/* vim: set noet ts=4 sw=4 ft=c ff=dos fenc=euc-jp : */
