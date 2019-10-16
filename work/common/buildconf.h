#ifndef INC_BUILDCONF_H
#define INC_BUILDCONF_H

/*
 * One build flag must be passed to the C preprocessor when building the project.
 * See the project documentation for the default configuration if you are unsure.
 * ********** ONLY ONE CONFIGURATION MAY BE DEFINED AT BUILD TIME!! **********
 */

/*---------------------------------------------------------------------------*
 * Definition Check
 *---------------------------------------------------------------------------*/
#if (( BUILD_SLPM86111 \
     + BUILD_SLUS00594_v10 \
     + BUILD_SLUS00594_v11 \
     + BUILD_SLES01370 \
     + BUILD_SLES01507 \
     + BUILD_SLES01506 \
     + BUILD_SLES01508 \
     + BUILD_SLES01734_v10 \
     + BUILD_SLES01734_v11 \
     + BUILD_SLPM80254 \
     + BUILD_SLPM86098 \
     + BUILD_PAPX90044 \
     + BUILD_SLUS90035 \
     + BUILD_SLED01400 \
     + BUILD_SLED01775 \
     + BUILD_SLPM86247 \
     + BUILD_SLPM86249 \
     + BUILD_SLUS00957 \
     + BUILD_SLUS90062 \
     + BUILD_SLES02136 \
     + BUILD_MGS_WIN32_INTEGRAL \
     + BUILD_MGS_WIN32_VRONLY \
     + BUILD_MGS_WIN32_DEMO0 \
     + BUILD_MGS4_FR \
     + BUILD_MGS4_GR \
     + BUILD_MGS4_IT \
     + BUILD_MGS4_JP \
     + BUILD_MGS4_SP \
     + BUILD_MGS4_US ) != 1 )
#error "Config flag error!! 0 or >1 flags were defined."
#endif

/*---------------------------------------------------------------------------*
 * Alias Definition
 *---------------------------------------------------------------------------*/

/* --- METAL GEAR SOLID --- */

#define MGS_JPN             BUILD_SLPM86111     // Jul.24,1998
#define MGS_USA_v10         BUILD_SLUS00594_v10 // Sep.09,1998 ver.1.0
#define MGS_USA_v11         BUILD_SLUS00594_v11 // Sep.16,1998 ver.1.1
#define MGS_PAL_EN          BUILD_SLES01370     // Nov.19,1998 English
#define MGS_PAL_DE          BUILD_SLES01507     // Nov.30,1998 German
#define MGS_PAL_FR          BUILD_SLES01506     // Dec.28,1998 French
#define MGS_PAL_IT          BUILD_SLES01508     // Feb.09,1999 Italian
#define MGS_PAL_ES_v10      BUILD_SLES01734_v10 // Apr.05,1999 Spanish ver.1.0
#define MGS_PAL_ES_v11      BUILD_SLES01734_v11 // Jul.15,1999 Spanish ver.1.1

/* --- METAL GEAR SOLID PILOT DISC --- */

#define MGS_PILOT_DISC1     BUILD_SLPM80254     // Apr.27,1998 PILOT DISC
#define MGS_DEMO_JPN        BUILD_SLPM86098     // Jun.18,1998 JPN DEMO
#define MGS_PILOT_DISC2     BUILD_PAPX90044     // Jun.30,1998 PILOT DISC
#define MGS_DEMO_USA        BUILD_SLUS90035     // Aug.03,1998 USA DEMO
#define MGS_DEMO_PAL1       BUILD_SLED01400     // Aug.04,1998 PAL DEMO
#define MGS_DEMO_PAL2       BUILD_SLED01775     // Dec.01,1998 PAL DEMO

/* --- METAL GEAR SOLID INTEGRAL (PlayStation) --- */

#define MGS_INTEGRAL        BUILD_SLPM86247     // May.07,1999 INTEGRAL DISC 1/2
#define MGSVR_JPN           BUILD_SLPM86249     // May.10,1999 INTEGRAL VR DISC
#define MGSVR_USA           BUILD_SLUS00957     // Jun.25,1999 VR MISSIONS
#define MGSVR_USA_DEMO      BUILD_SLUS90062     // Jul.13,1999 VR MISSIONS DEMO
#define MGSVR_PAL           BUILD_SLES02136     // Aug.16,1999 SPECIAL MISSIONS

/* --- METAL GEAR SOLID INTEGRAL (Windows) --- */

#define MGS_WIN32_INTEGRAL  BUILD_MGS_WIN32_INTEGRAL // Aug.28,2000 mgsi.exe
#define MGS_WIN32_VRONLY    BUILD_MGS_WIN32_VRONLY   // Aug.28,2000 mgsvr.exe
#define MGS_WIN32_DEMO0     BUILD_MGS_WIN32_DEMO0    // Oct.04,2000 mgsiDEMO.exe

/* --- METAL GEAR SOLID 4 (PSX MODULE) --- */

#define MGS4_FR             BUILD_MGS4_FR       // Nov.28,2007 mgs/stage/module/fr.self
#define MGS4_GR             BUILD_MGS4_GR       // Nov.28,2007 mgs/stage/module/gr.self
#define MGS4_IT             BUILD_MGS4_IT       // Nov.28,2007 mgs/stage/module/it.self
#define MGS4_JP             BUILD_MGS4_JP       // Nov.28,2007 mgs/stage/module/jp.self
#define MGS4_SP             BUILD_MGS4_SP       // Nov.28,2007 mgs/stage/module/sp.self
#define MGS4_US             BUILD_MGS4_US       // Nov.28,2007 mgs/stage/module/us.self

/*---------------------------------------------------------------------------*/
#endif /* END OF FILE */
/*---------------------------------------------------------------------------*/
/* -*- indent-tabs-mode: t; tab-width: 4; mode: c; -*- */
/* vim: set noet ts=4 sw=4 ft=c ff=dos fenc=utf-8 : */
