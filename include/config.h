/*
 *  Copyright (C) 2002-2017  The DOSBox Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

 /* Version number of package */
#define VERSION "SVN"

#include <stdint.h>
typedef uint8_t   Bit8u;
typedef int8_t    Bit8s;
typedef uint16_t  Bit16u;
typedef int16_t   Bit16s;
typedef uint32_t  Bit32u;
typedef int32_t   Bit32s;
typedef uint64_t  Bit64u;
typedef int64_t   Bit64s;
#if (__WORDSIZE == 64)
typedef Bit64u Bitu;
typedef Bit64s Bits;
#else
typedef Bit32u Bitu;
typedef Bit32s Bits;
#endif
