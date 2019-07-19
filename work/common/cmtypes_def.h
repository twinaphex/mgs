#ifndef INC_CMTYPES_DEF_H
#define INC_CMTYPES_DEF_H

/* 8-bit */
#define byte     char
#define int8     char
#define char8    char

/* 16-bit */
#define int16    short
#define short16  short

/* 32-bit */
#define int32    int
#define long32   int

/* 64-bit */
#define llong    long long
#define int64    long long
#define long64   long long

/* basic */
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

/* size-specific */
typedef   signed char       sint8,  s_int8,  s8,  schar8,   s_char8;
typedef unsigned char       uint8,  u_int8,  u8,  uchar8,   u_char8;
typedef   signed short      sint16, s_int16, s16, sshort16, s_short16;
typedef unsigned short      uint16, u_int16, u16, ushort16, u_short16;
typedef   signed int        sint32, s_int32, s32, slong32,  s_long32;
typedef unsigned int        uint32, u_int32, u32, ulong32,  u_long32;
typedef   signed long long  sint64, s_int64, s64, slong64,  s_long64;
typedef unsigned long long  uint64, u_int64, u64, ulong64,  u_long64;

typedef float   float32, f32;
typedef double  float64, f64;

/* fake boolean */
typedef int8   bool8;
typedef int16  bool16;
typedef int32  bool32;
typedef int64  bool64;

#ifndef TRUE
#define TRUE  (1)
#endif
#ifndef FALSE
#define FALSE (0)
#endif

/* union */
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
} union128;

#endif /* INC_CMTYPES_DEF_H */