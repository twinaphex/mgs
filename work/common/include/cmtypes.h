/*
 *【 LibCM 】by J.Ingram
 * Common Type Definitions
 */
#ifndef INC_CMTYPES_H
#define INC_CMTYPES_H

#include "cmconf.h"

/*---------------------------------------------------------------------------*/
/* Integer Types w/ Unspecified Sign                                         */
/*---------------------------------------------------------------------------*/
#ifndef byte
#define byte     CM_TYPE_INT8
#endif
#ifndef llong
#define llong    long long
#endif

#ifndef int8
#define int8     CM_TYPE_INT8
#endif
#ifndef int16
#define int16    CM_TYPE_INT16
#endif
#ifndef int32
#define int32    CM_TYPE_INT32
#endif
#ifndef int64
#define int64    CM_TYPE_INT64
#endif

#ifndef char8
#define char8    CM_TYPE_INT8
#endif
#ifndef short16
#define short16  CM_TYPE_INT16
#endif
#ifndef short32
#define short32  CM_TYPE_INT32
#endif
#ifndef long32
#define long32   CM_TYPE_INT32
#endif
#ifndef long64
#define long64   CM_TYPE_INT64
#endif

/*---------------------------------------------------------------------------*/
/* Integer Types w/ Unspecified Width                                        */
/*---------------------------------------------------------------------------*/
typedef   signed char       schar,  s_char;
typedef unsigned char       uchar,  u_char;
typedef   signed short      sshort, s_short;
typedef unsigned short      ushort, u_short;
typedef   signed int        sint,   s_int;
typedef unsigned int        uint,   u_int;
typedef   signed long       slong,  s_long;
typedef unsigned long       ulong,  u_long;
typedef   signed long long  sllong, s_llong;
typedef unsigned long long  ullong, u_llong;

/*---------------------------------------------------------------------------*/
/* Integer Types w/ Specified Width                                          */
/*---------------------------------------------------------------------------*/
typedef   signed CM_TYPE_INT8   sbyte,  s_byte;
typedef unsigned CM_TYPE_INT8   ubyte,  u_byte;

typedef   signed CM_TYPE_INT8   sint8,  s_int8,  s8;
typedef unsigned CM_TYPE_INT8   uint8,  u_int8,  u8;
typedef   signed CM_TYPE_INT16  sint16, s_int16, s16;
typedef unsigned CM_TYPE_INT16  uint16, u_int16, u16;
typedef   signed CM_TYPE_INT32  sint32, s_int32, s32;
typedef unsigned CM_TYPE_INT32  uint32, u_int32, u32;
typedef   signed CM_TYPE_INT64  sint64, s_int64, s64;
typedef unsigned CM_TYPE_INT64  uint64, u_int64, u64;

typedef   signed CM_TYPE_INT8   schar8,   s_char8;
typedef unsigned CM_TYPE_INT8   uchar8,   u_char8;
typedef   signed CM_TYPE_INT16  sshort16, s_short16;
typedef unsigned CM_TYPE_INT16  ushort16, u_short16;
typedef   signed CM_TYPE_INT32  sshort32, s_short32;
typedef unsigned CM_TYPE_INT32  ushort32, u_short32;
typedef   signed CM_TYPE_INT32  slong32,  s_long32;
typedef unsigned CM_TYPE_INT32  ulong32,  u_long32;
typedef   signed CM_TYPE_INT64  slong64,  s_long64;
typedef unsigned CM_TYPE_INT64  ulong64,  u_long64;

/*---------------------------------------------------------------------------*/
/* Floating Point Types w/ Specified Width                                   */
/*---------------------------------------------------------------------------*/
typedef CM_TYPE_FLOAT32  float32, f32;
typedef CM_TYPE_FLOAT64  float64, f64;

#ifdef CM_HAVE_MODETF
typedef float float128 __attribute__((mode(TF)));
typedef float f128     __attribute__((mode(TF)));
#endif
#ifdef CM_HAVE_MODEXF
typedef float float96  __attribute__((mode(XF)));
typedef float f96      __attribute__((mode(XF)));
#endif

/*---------------------------------------------------------------------------*/
/* 128bit Integer Types (Tetra-Integer Mode)                                 */
/*---------------------------------------------------------------------------*/
#ifdef CM_HAVE_MODETI
typedef /******/ int int128    __attribute__((mode(TI)));
typedef /******/ int long128   __attribute__((mode(TI)));
typedef   signed int sint128   __attribute__((mode(TI)));
typedef unsigned int uint128   __attribute__((mode(TI)));
typedef   signed int slong128  __attribute__((mode(TI)));
typedef unsigned int ulong128  __attribute__((mode(TI)));
typedef   signed int s_int128  __attribute__((mode(TI)));
typedef unsigned int u_int128  __attribute__((mode(TI)));
typedef   signed int s_long128 __attribute__((mode(TI)));
typedef unsigned int u_long128 __attribute__((mode(TI)));
typedef   signed int s128      __attribute__((mode(TI)));
typedef unsigned int u128      __attribute__((mode(TI)));
#endif

/*---------------------------------------------------------------------------*/
/* Fake Boolean Types                                                        */
/*---------------------------------------------------------------------------*/
#ifndef bool8
#define bool8  CM_TYPE_INT8
#endif
#ifndef bool16
#define bool16 CM_TYPE_INT16
#endif
#ifndef bool32
#define bool32 CM_TYPE_INT32
#endif
#ifndef bool64
#define bool64 CM_TYPE_INT64
#endif

#ifndef TRUE
#define TRUE  (1)
#endif
#ifndef FALSE
#define FALSE (0)
#endif

/*---------------------------------------------------------------------------*/
/* Generic Union Types                                                       */
/*---------------------------------------------------------------------------*/

/* 8-bit (1 Byte) */
typedef union union8 {
	struct {
		byte bit0:1; /* LSB */
		byte bit1:1;
		byte bit2:1;
		byte bit3:1;
		byte bit4:1;
		byte bit5:1;
		byte bit6:1;
		byte bit7:1; /* MSB */
	};
	s_int8 s8;
	u_int8 u8;
} union8;

/* 16-bit (2 Bytes) */
typedef union union16 {
	s_int16 s16;
	u_int16 u16;
	s_int8  s8[2];
	u_int8  u8[2];
	union8  c8[2];
} union16;

/* 32-bit (4 Bytes) */
typedef union union32 {
	s_int32 s32;
	u_int32 u32;
	float32 f32;
	s_int16 s16[2];
	u_int16 u16[2];
	union16 c16[2];
	s_int8  s8[4];
	u_int8  u8[4];
	union8  c8[4];
} union32;

/* 64-bit (8 Bytes) */
typedef union union64 {
	s_int64 s64;
	u_int64 u64;
	float64 f64;
	s_int32 s32[2];
	u_int32 u32[2];
	float32 f32[2];
	union32 c32[2];
	s_int16 s16[4];
	u_int16 u16[4];
	union16 c16[4];
	s_int8  s8[8];
	u_int8  u8[8];
	union8  c8[8];
} union64;

/* 128-bit (16 Bytes) */
typedef union union128 {
#ifdef CM_HAVE_INT128
	s_int128 s128;
	u_int128 u128;
#endif
#ifdef CM_HAVE_FLOAT128
	float128 f128;
#endif
	s_int64  s64[2];
	u_int64  u64[2];
	float64  f64[2];
	union64  c64[2];
	s_int32  s32[4];
	u_int32  u32[4];
	float32  f32[4];
	union32  c32[4];
	s_int16  s16[8];
	u_int16  u16[8];
	union16  c16[8];
	s_int8   s8[16];
	u_int8   u8[16];
	union8   c8[16];
} union128;

/*---------------------------------------------------------------------------*/
#endif /* END OF FILE */
/*---------------------------------------------------------------------------*/
/* -*- indent-tabs-mode: t; tab-width: 4; mode: c; -*- */
/* vim: set noet ts=4 sw=4 ft=c ff=unix fenc=utf-8 : */
