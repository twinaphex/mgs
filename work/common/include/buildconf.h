#ifndef INC_BUILDCONF_H
#define INC_BUILDCONF_H

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
     + BUILD_WIN32_INTEGRAL \
     + BUILD_WIN32_VRONLY \
     + BUILD_WIN32_DEMO0 \
     + BUILD_PSX_MGS4_FR \
     + BUILD_PSX_MGS4_GR \
     + BUILD_PSX_MGS4_IT \
     + BUILD_PSX_MGS4_JP \
     + BUILD_PSX_MGS4_SP \
     + BUILD_PSX_MGS4_US \
     + BUILD_NEW ) != 1 )
#error "ERROR: 0 or >1 config flags defined."
#endif

/*---------------------------------------------------------------------------*
 * Alias Definition
 *---------------------------------------------------------------------------*/

/* --- METAL GEAR SOLID --- */

#define PSX_JPN             BUILD_SLPM86111     // Jul.24,1998
#define PSX_USA_v10         BUILD_SLUS00594_v10 // Sep.09,1998 ver.1.0
#define PSX_USA_v11         BUILD_SLUS00594_v11 // Sep.16,1998 ver.1.1
#define PSX_PAL_EN          BUILD_SLES01370     // Nov.19,1998 English
#define PSX_PAL_GR          BUILD_SLES01507     // Nov.30,1998 German
#define PSX_PAL_FR          BUILD_SLES01506     // Dec.28,1998 French
#define PSX_PAL_IT          BUILD_SLES01508     // Feb.09,1999 Italian
#define PSX_PAL_SP_v10      BUILD_SLES01734_v10 // Apr.05,1999 Spanish ver.1.0
#define PSX_PAL_SP_v11      BUILD_SLES01734_v11 // Jul.15,1999 Spanish ver.1.1

/* --- METAL GEAR SOLID PILOT DISC --- */

#define PSX_PILOT_DISC1     BUILD_SLPM80254     // Apr.27,1998 PILOT DISC
#define PSX_DEMO_JPN        BUILD_SLPM86098     // Jun.18,1998 JPN DEMO
#define PSX_PILOT_DISC2     BUILD_PAPX90044     // Jun.30,1998 PILOT DISC
#define PSX_DEMO_USA        BUILD_SLUS90035     // Aug.03,1998 USA DEMO
#define PSX_DEMO_PAL1       BUILD_SLED01400     // Aug.04,1998 PAL DEMO
#define PSX_DEMO_PAL2       BUILD_SLED01775     // Dec.01,1998 PAL DEMO

/* --- METAL GEAR SOLID INTEGRAL (PlayStation) --- */

#define PSX_INTEGRAL        BUILD_SLPM86247     // May.07,1999 INTEGRAL DISC 1/2
#define PSX_VR_JPN          BUILD_SLPM86249     // May.10,1999 INTEGRAL VR DISC
#define PSX_VR_USA          BUILD_SLUS00957     // Jun.25,1999 VR MISSIONS
#define PSX_VR_USA_DEMO     BUILD_SLUS90062     // Jul.13,1999 VR MISSIONS DEMO
#define PSX_VR_PAL          BUILD_SLES02136     // Aug.16,1999 SPECIAL MISSIONS

/* --- METAL GEAR SOLID INTEGRAL (Windows) --- */

#define WIN32_INTEGRAL      BUILD_WIN32_INTEGRAL    // Aug.28,2000 mgsi.exe
#define WIN32_VRONLY        BUILD_WIN32_VRONLY      // Aug.28,2000 mgsvr.exe
#define WIN32_DEMO0         BUILD_WIN32_DEMO0       // Oct.04,2000 mgsiDEMO.exe

/* --- METAL GEAR SOLID 4 (PSX MODULE) --- */

#define PSX_MGS4_FR         BUILD_PSX_MGS4_FR   // Nov.28,2007 mgs/stage/module/fr.self
#define PSX_MGS4_GR         BUILD_PSX_MGS4_GR   // Nov.28,2007 mgs/stage/module/gr.self
#define PSX_MGS4_IT         BUILD_PSX_MGS4_IT   // Nov.28,2007 mgs/stage/module/it.self
#define PSX_MGS4_JP         BUILD_PSX_MGS4_JP   // Nov.28,2007 mgs/stage/module/jp.self
#define PSX_MGS4_SP         BUILD_PSX_MGS4_SP   // Nov.28,2007 mgs/stage/module/sp.self
#define PSX_MGS4_US         BUILD_PSX_MGS4_US   // Nov.28,2007 mgs/stage/module/us.self

/*---------------------------------------------------------------------------*/
#endif /* END OF FILE */
/*---------------------------------------------------------------------------*/
/* -*- indent-tabs-mode: t; tab-width: 4; mode: c; -*- */
/* vim: set noet ts=4 sw=4 ft=c ff=unix fenc=utf-8 : */
