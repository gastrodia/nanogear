/*
 * Nanogear - C++ web development framework
 *
 * This library is based on Restlet (R) <http://www.restlet.org> by Noelios Technologies
 * Copyright (C) 2005-2008 by Noelios Technologies <http://www.noelios.com>
 * Restlet is a registered trademark of Noelios Technologies. All other marks and
 * trademarks are property of their respective owners.
 *
 * Copyright (C) 2008 Lorenzo Villani.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */



#ifndef NANOGEAR_REST_UNIFORM_HPP
#define NANOGEAR_REST_UNIFORM_HPP

#include "data/response.hpp"
#include "data/reference.hpp"

namespace nanogear {
namespace rest {

/**
 *
 * @author Lorenzo Villani <lvillani@binaryhelix.net>
 */
class uniform {
public:
    uniform() {};
    ~uniform() {};

    data::response delete_resource(const data::reference&);

    data::response resource(const data::reference&);

    data::response handle(const data::request&);
    data::response handle(const data::request&, const data::response&);

    data::response head(const data::reference&);

    data::response options(const data::reference&);

    data::response post(const data::reference&);

    data::response put(const data::reference&);
};

}
}

#endif /* NANOGEAR_REST_UNIFORM_HPP */
