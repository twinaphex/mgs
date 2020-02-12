/*
 * [ LibDG ]
 * Image Drawing/Display Library
 */
#ifndef INC_LIBDG_H
#define INC_LIBDG_H

#include <sys/types.h>
#include <libgte.h>
#include <libgpu.h>

/*---------------------------------------------------------------------------*
 * Common Types
 *---------------------------------------------------------------------------*/

// temp forward declaration
typedef struct _DG_MDL DG_MDL;
typedef struct _DG_DEF DG_DEF;

// ref.SLPM86249:vijkl_08.bin
/* *************************** */
/* ===== START QUOTATION ===== */
/* *************************** */

typedef struct _DG_OBJ {
        MATRIX          world ;         /**/
        MATRIX          screen ;        /**/
        DG_MDL          *model ;        /**/
        CVECTOR         *rgbs;          /**/
        struct _DG_OBJ  *extend ;       /**/
        short           bound_mode ;    /**/
        short           free_count ;    /**/
        short           raise ;         /**/
        short           n_packs ;       /**/
        POLY_GT4        *packs[ 2 ] ;   /**/
} DG_OBJ ;

typedef struct {
        MATRIX          world ;         /**/
        MATRIX          *root ;         /**/
        DG_DEF          *def ;          /**/
        u_long          flag ;          /**/
        u_short         group_id ;      /**/
        short           n_models ;      /**/
        short           chanl ;         /**/
        short           bound_mode ;    /**/
        MATRIX          *light ;        /**/
        SVECTOR         *rots ;         /**/
        SVECTOR         *adjust ;       /**/
        SVECTOR         *waist_rot;     /**/
        SVECTOR         *movs ;         /**/
        DG_OBJ          objs[ 0 ] ;     /**/
} DG_OBJS ;

enum {
        DG_FLAG_TEXT            = 0x0001,       /**/
        DG_FLAG_PAINT           = 0x0002,       /**/
        DG_FLAG_TRANS           = 0x0004,       /**/
        DG_FLAG_SHADE           = 0x0008,       /**/
        DG_FLAG_BOUND           = 0x0010,       /**/
        DG_FLAG_GBOUND          = 0x0020,       /**/
        DG_FLAG_ONEPIECE        = 0x0040,       /**/
        DG_FLAG_INVISIBLE       = 0x0080,       /**/
        DG_FLAG_AMBIENT         = 0x0100,       /**/
        /***** (TRUNCATED) *****/
};

/* ************************* */
/* ===== END QUOTATION ===== */
/* ************************* */

/*---------------------------------------------------------------------------*
 * Inline Functions
 *---------------------------------------------------------------------------*/

// ref.SLES02136:vijkl_03.bin
/* *************************** */
/* ===== START QUOTATION ===== */
/* *************************** */

static  inline  void    DG_VisibleObjs( objs )
DG_OBJS                 *objs ;
{
        objs->flag &= ~DG_FLAG_INVISIBLE ;
}

static  inline  void    DG_InvisibleObjs( objs )
DG_OBJS                 *objs ;
{
        objs->flag |= DG_FLAG_INVISIBLE ;
}

static  inline  void    DG_SetCurrentGroup( group_id )
int                     group_id ;
{
        extern  int     DG_CurrentGroupID ;

        DG_CurrentGroupID = group_id ;
}

/* ************************* */
/* ===== END QUOTATION ===== */
/* ************************* */

/*---------------------------------------------------------------------------*
 * Prototypes
 *---------------------------------------------------------------------------*/

/* DG Daemon (dgd.c) */
extern void DG_StartDaemon( void );

/*---------------------------------------------------------------------------*/
#endif /* END OF FILE */
/*---------------------------------------------------------------------------*/
/* -*- indent-tabs-mode: t; tab-width: 4; mode: c; -*- */
/* vim: set noet ts=4 sw=4 ft=c ff=dos fenc=euc-jp : */
