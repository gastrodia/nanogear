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

#ifndef NANOGEAR_REST_HTTP_ENGINE_HPP
#define NANOGEAR_REST_HTTP_ENGINE_HPP

#include <nanogear/rest/util/engine.hpp>

namespace nanogear {
namespace rest {
namespace http {
class engine : public util::engine {
    static helper<application>::ptr create(application*);
    static helper<abstract_client>::ptr create(abstract_client*);
    static helper<component>::ptr create(component*);
    static helper<abstract_server>::ptr create(abstract_server*);
};
}
}
}


#endif /* NANOGEAR_REST_HTTP_ENGINE_HPP */
