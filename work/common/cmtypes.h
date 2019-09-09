#ifndef INC_CMTYPES_H
#define INC_CMTYPES_H

/*---------------------------------------------------------------------------*
 * Platform Configuration
 *---------------------------------------------------------------------------*/
#if defined( __GNUC__ )

#if defined( __i686__ )\
 || defined( __x86_64__ )
#define HASTYPE_FLOAT128
#endif /* (ARCH) */

#if defined( __i686__ )
#define HASTYPE_FLOAT96
#endif /* (ARCH) */

#if defined( __x86_64__ )\
 || defined( __ee__ )  /* PS2 Emotion Engine */\
 || defined( __psp__ ) /* PSP Allegrex       */\
 || defined( __PPU__ ) /* PS3 Cell/B.E. PPU  */\
 || defined( __SPU__ ) /* PS3 Cell/B.E. SPU  */
#define HASTYPE_INT128
#endif /* (ARCH) */

#endif /* __GNUC__ */

/*---------------------------------------------------------------------------*
 * Conflict Check
 *---------------------------------------------------------------------------*/
#if defined( __psp__ )
#if defined( _SCE_PSPTYPES_H )\
 && !defined( SCE_PSPTYPES_SUPPRESS_ADDITIONAL_DEFINE )
#error "psptypes.h was included before conflict suppression!!"
#else /* _SCE_PSPTYPES_H && !SCE_PSPTYPES_SUPPRESS_ADDITIONAL_DEFINE */
#ifndef SCE_PSPTYPES_SUPPRESS_ADDITIONAL_DEFINE
#define SCE_PSPTYPES_SUPPRESS_ADDITIONAL_DEFINE
#endif /* SCE_PSPTYPES_SUPPRESS_ADDITIONAL_DEFINE */
#endif /* _SCE_PSPTYPES_H && !SCE_PSPTYPES_SUPPRESS_ADDITIONAL_DEFINE */
#endif /* __psp__ */

/*---------------------------------------------------------------------------*
 * Common Types w/ Unspecified Sign
 *---------------------------------------------------------------------------*/
#ifndef byte
#define byte     char
#endif
#ifndef llong
#define llong    long long
#endif

#ifndef int8
#define int8     char
#endif
#ifndef int16
#define int16    short
#endif
#ifndef int32
#define int32    int
#endif
#ifndef int64
#define int64    long long
#endif

#ifndef char8
#define char8    char
#endif
#ifndef short16
#define short16  short
#endif
#ifndef long32
#define long32   int
#endif
#ifndef long64
#define long64   long long
#endif

/*---------------------------------------------------------------------------*
 * Common Types w/ Unspecified Width
 *---------------------------------------------------------------------------*/
typedef   signed char       sbyte,  s_byte;
typedef unsigned char       ubyte,  u_byte;
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

/*---------------------------------------------------------------------------*
 * Common Types w/ Specified Width
 *---------------------------------------------------------------------------*/
typedef   signed int8       sint8,  s_int8,  s8,  schar8,   s_char8;
typedef unsigned int8       uint8,  u_int8,  u8,  uchar8,   u_char8;
typedef   signed int16      sint16, s_int16, s16, sshort16, s_short16;
typedef unsigned int16      uint16, u_int16, u16, ushort16, u_short16;
typedef   signed int32      sint32, s_int32, s32, slong32,  s_long32;
typedef unsigned int32      uint32, u_int32, u32, ulong32,  u_long32;
typedef   signed int64      sint64, s_int64, s64, slong64,  s_long64;
typedef unsigned int64      uint64, u_int64, u64, ulong64,  u_long64;

typedef float   float32, f32;
typedef double  float64, f64;

#if defined( __GNUC__ )
#if defined( HASTYPE_FLOAT128 )
typedef float float128 __attribute__((mode(TF)));
typedef float f128     __attribute__((mode(TF)));
#endif /* HASTYPE_FLOAT128 */
#if defined( HASTYPE_FLOAT96 )
typedef float float96  __attribute__((mode(XF)));
typedef float f96      __attribute__((mode(XF)));
#endif /* HASTYPE_FLOAT96 */
#endif /* __GNUC__ */

#if defined( __GNUC__ )
#if defined( HASTYPE_INT128 )
typedef          int int128    __attribute__((mode(TI)));
typedef          int long128   __attribute__((mode(TI)));
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
#endif /* HASTYPE_INT128 */
#endif /* __GNUC__ */

/*---------------------------------------------------------------------------*
 * Fake Boolean Types
 *---------------------------------------------------------------------------*/
#ifndef bool8
#define bool8  int8
#endif
#ifndef bool16
#define bool16 int16
#endif
#ifndef bool32
#define bool32 int32
#endif
#ifndef bool64
#define bool64 int64
#endif

#ifndef TRUE
#define TRUE  (1)
#endif
#ifndef FALSE
#define FALSE (0)
#endif

/*---------------------------------------------------------------------------*
 * Generic Union Types
 *---------------------------------------------------------------------------*/
typedef union union16 {
	s_int16 s16;
	u_int16 u16;
	s_int8  s8[2];
	u_int8  u8[2];
} union16;

typedef union union32 {
	s_int32 s32;
	u_int32 u32;
	s_int16 s16[2];
	u_int16 u16[2];
	s_int8  s8[4];
	u_int8  u8[4];
	float32 f32;
} union32;

typedef union union64 {
	s_int64 s64;
	u_int64 u64;
	s_int32 s32[2];
	u_int32 u32[2];
	s_int16 s16[4];
	u_int16 u16[4];
	s_int8  s8[8];
	u_int8  u8[8];
	float32 f32[2];
	float64 f64;
} union64;

typedef union union128 {
#if defined( HASTYPE_INT128 )
	s_int128 s128;
	u_int128 u128;
#endif /* HASTYPE_INT128 */
	s_int64  s64[2];
	u_int64  u64[2];
	s_int32  s32[4];
	u_int32  u32[4];
	s_int16  s16[8];
	u_int16  u16[8];
	s_int8   s8[16];
	u_int8   u8[16];
	float32  f32[4];
	float64  f64[2];
#if defined( HASTYPE_FLOAT128 )
	float128 f128;
#endif /* HASTYPE_FLOAT128 */
} union128;

/*---------------------------------------------------------------------------*
 * END OF FILE
 *---------------------------------------------------------------------------*/
#endif /* INC_CMTYPES_H */
