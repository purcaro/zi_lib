//
// Copyright (C) 2010  Aleksandar Zlateski <zlateski@mit.edu>
// ----------------------------------------------------------
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef ZI_UTILITY_FOR_EACH_HPP
#define ZI_UTILITY_FOR_EACH_HPP 1

#include <zi/bits/typeof.hpp>

#if defined ( __typeof__ )

#  define FOR_EACH( it, cnt )                                   \
    FOR_EACH_RANGE( it, ( cnt ).begin(), ( cnt ).end() )

#  define FOR_EACH_R( it, cnt )                                 \
    FOR_EACH_RANGE( it, ( cnt ).rbegin(), ( cnt ).rend() )

#  define FOR_EACH_RANGE( it, begin, end )                              \
    for (__typeof__( begin ) it = ( begin ); it != ( end ); ++it)


#  ifdef ZI_LOWERCASE_FOREACH
#
#    ifndef foreach
#      define foreach( it, cnt ) FOR_EACH( it, cnt )
#    endif
#
#    ifndef foreach_r
#      define foreach_r( it, cnt ) FOR_EACH_R( it, cnt )
#    endif
#
#    ifndef foreach_range
#      define foreach_range( it, begin, end ) FOR_EACH_RANGE( it, begin, end )
#    endif
#
#  endif // ZI_NO_LOWERCASE_FOREACH

#else  // defined( __typeof__ ) not defined
#  error "can't define FOR_EACH macros with no __typeof__ defined"

#endif // defined( __typeof__ )

#endif
