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



#ifndef NANOGEAR_RESTUNIFORM_HPP
#define NANOGEAR_RESTUNIFORM_HPP

namespace nanogear {
namespace rest {

namespace data {
class response;
}

/**
 *
 * @author Lorenzo Villani <lvillani@binaryhelix.net>
 */
class uniform {
public:
    uniform();
    ~uniform();

    response delete_resource(const reference&);
    response delete_resource(const std::string&);

    response get_resource(const reference&);
    response get_resource(const std::string&);

    response handle(const request&);
    response handle(const request&, const response&);

    response head(const reference&);
    response head(const std::string&);

    response options(const reference&);
    response options(const std::string&);

    response post(const reference&);
    response post(const std::string&);

    response put(const reference&);
    response put(const std::string&);
};

}
}

#endif /* NANOGEAR_RESTUNIFORM_HPP */
