/*
 *  String Hash Function
 */
#include "mgs_defs.h"
#include "mgs_types.h"

/*
 * Warning:
 * - Given that the digest is only 16 bits wide, this algorithm is highly
 *   prone to collisions. Check for collisions after precalculating a set
 *   of hashes intended for use at runtime. (e.g. stage data files)
 *
 * Behavior:
 * - Passing an empty string will return zero.
 * - Passing a single-char string will return the value of the char.
 * - Permutations of strings differing in only the last character will
 *   result in the lowest byte of the hash mirroring that difference.
 *
 *   Examples:
 *      GV_StrCode( "cb_box11" )  == 0xADDB
 *      GV_StrCode( "cb_box12" )  == 0xADDC
 *      GV_StrCode( "op_kcej_l" ) == 0x4349
 *      GV_StrCode( "op_kcej_r" ) == 0x434F
 */

/* status: NOMATCH, opt: -O2, instr: good, regs: bad */
u_short GV_StrCode( char *string )
{
	u_char c;
	u_int id = 0;
	
	while ( c = *string++ )
	{
		id &= 0xFFFF;
		id = (( id >> 11 ) | ( id << 5 ));
		id += c;
	}
	return id; // implicit &= 0xFFFF
}

/* vim: set noet ts=4 sw=4 ff=dos fenc=euc-jp: */
