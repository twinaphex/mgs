/*
 * Multi-Task Scheduler for PSX ver2.02
 * Private Include (for MTS ONLY)
 */
#ifndef INC_PRIVATE_H
#define INC_PRIVATE_H

#include "global.h"

/*---------------------------------------------------------------------------*
 * Build Config Defines
 *---------------------------------------------------------------------------*/
/* Predefinition of previously expanded __DATE__ and __TIME__ macros.
 * These must be manually defined in order to build a matching object
 * from "mts_new.c". For new, non-matching builds, the appropriate
 * date and time will be inserted. */
/* -------------------------------------------------- */
#if (PSX_PILOT_DISC1)     /* [SLPM-80254] Apr.27,1998 */

#define MTS_BUILD_DATE  "Mar 17 1998"
#define MTS_BUILD_TIME  "20:53:30"
/* -------------------------------------------------- */
#elif (PSX_DEMO_JPN)      /* [SLPM-86098] Jun.18,1998 */\
||    (PSX_PILOT_DISC2)   /* [PAPX-90044] Jun.30,1998 */\
||    (PSX_DEMO_USA)      /* [SLUS-90035] Aug.03,1998 */\
||    (PSX_DEMO_PAL1)     /* [SLED-01400] Aug.04,1998 */

#define MTS_BUILD_DATE  "Jun 13 1998"
#define MTS_BUILD_TIME  "15:05:16"
/* -------------------------------------------------- */
#elif (PSX_JPN)           /* [SLPM-86111] Jul.24,1998 */\
||    (PSX_USA_v10)       /* [SLUS-00594] Sep.09,1998 */\
||    (PSX_USA_v11)       /* [SLUS-00594] Sep.16,1998 */\
||    (PSX_PAL_EN)        /* [SLES-01370] Nov.19,1998 */\
||    (PSX_PAL_GR)        /* [SLES-01507] Nov.30,1998 */\
||    (PSX_PAL_FR)        /* [SLES-01506] Dec.28,1998 */\
||    (PSX_INTEGRAL)      /* [SLPM-86247] May.07,1999 */\
||    (PSX_VR_JPN)        /* [SLPM-86249] May.10,1999 */

#define MTS_BUILD_DATE  "Jul 11 1998"
#define MTS_BUILD_TIME  "22:16:33"
/* -------------------------------------------------- */
#elif (PSX_DEMO_PAL2)     /* [SLED-01775] Dec.01,1998 */

#define MTS_BUILD_DATE  "Nov 12 1998"
#define MTS_BUILD_TIME  "18:51:44"
/* -------------------------------------------------- */
#elif (PSX_PAL_IT)        /* [SLES-01508] Feb.09,1999 */\
||    (PSX_PAL_SP_v10)    /* [SLES-01734] Apr.05,1999 */\
||    (PSX_PAL_SP_v11)    /* [SLES-01734] Jul.15,1999 */\
||    (PSX_VR_USA)        /* [SLUS-00957] Jun.25,1999 */\
||    (PSX_VR_PAL)        /* [SLES-02136] Aug.16,1999 */

#define MTS_BUILD_DATE  "Nov 12 1998"
#define MTS_BUILD_TIME  "20:00:47"
/* -------------------------------------------------- */
#elif (PSX_VR_USA_DEMO)   /* [SLUS-90062] Jul.13,1999 */

#define MTS_BUILD_DATE  "Jun 11 1999"
#define MTS_BUILD_TIME  "10:13:47"
/* -------------------------------------------------- */
#elif (PSX_MGS4_FR)     /* [NO PROD.CODE] Nov.28,2007 */\
||    (PSX_MGS4_GR)     /* [NO PROD.CODE] Nov.28,2007 */\
||    (PSX_MGS4_IT)     /* [NO PROD.CODE] Nov.28,2007 */\
||    (PSX_MGS4_JP)     /* [NO PROD.CODE] Nov.28,2007 */\
||    (PSX_MGS4_SP)     /* [NO PROD.CODE] Nov.28,2007 */\
||    (PSX_MGS4_US)     /* [NO PROD.CODE] Nov.28,2007 */

#define MTS_BUILD_DATE  "Aug 21 2007"
#define MTS_BUILD_TIME  "21:28:42"
/* -------------------------------------------------- */
#else /* NEW BUILD */

#define MTS_BUILD_DATE  __DATE__
#define MTS_BUILD_TIME  __TIME__
/* -------------------------------------------------- */
#endif /* (CHAIN) */

/*---------------------------------------------------------------------------*/
#endif /* END OF FILE */
/*---------------------------------------------------------------------------*/
/* -*- indent-tabs-mode: t; tab-width: 4; mode: c; -*- */
/* vim: set noet ts=4 sw=4 ft=c ff=dos fenc=euc-jp : */
