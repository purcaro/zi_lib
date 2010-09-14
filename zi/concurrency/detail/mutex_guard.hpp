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

#ifndef ZI_CONCURRENCY_DETAIL_MUTEX_GUARD_HPP
#define ZI_CONCURRENCY_DETAIL_MUTEX_GUARD_HPP 1

#include <zi/concurrency/config.hpp>
#include <zi/utility/non_copyable.hpp>

namespace zi {
namespace concurrency_ {

// forward declaration
class condition_variable;

template< class Mutex > class mutex_guard: non_copyable
{
private:

    const Mutex &m_;
    friend class condition_variable;

public:

    typedef mutex_guard< Mutex > guard_type;

    explicit mutex_guard( const Mutex &m ): m_( m )
    {
        m_.lock();
    }

    ~mutex_guard()
    {
        m_.unlock();
    }

};


} // namespace concurrency_
} // namespace zi

#endif
