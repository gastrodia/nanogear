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




#ifndef NANOGEAR_REST_CONTEXT_HPP
#define NANOGEAR_REST_CONTEXT_HPP

#include <map>
#include <list>
#include <string>
#include <boost/shared_ptr.hpp>

#include "data/parameter.hpp"

namespace nanogear {
namespace rest {
class uniform;
    
class context {
public:
    context();
    std::map<std::string, std::string>& get_attributes();
    std::list<data::parameter>& get_parameters();
    virtual boost::shared_ptr<uniform> get_dispatcher();

private:
    std::map<std::string, std::string> attributes;
    std::list<data::parameter> parameters;
};


}
}

#endif /* NANOGEAR_REST_CONTEXT_HPP */
