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

#include "server.hpp"
#include "util/engine.hpp"

namespace nanogear {
namespace rest {

abstract_server::abstract_server(const context& cont, const std::list<data::protocol>& protos,
               const int port, const std::string& address,
               const controller::ptr& control)
               : connector(cont, protos), m_address(address), m_port(port),
                 m_target(control) {}

const std::string& abstract_server::address() const
{
    return m_address;
}
const util::helper<abstract_server>::ptr& abstract_server::helper() const
{
    return m_helper;
}
int abstract_server::port() const
{
    return m_port;
}
const controller::ptr& abstract_server::target() const
{
    return m_target;
}
void abstract_server::operator()(const data::request& req, const data::response& res)
{
    connector::operator()(req, res);
    if (has_target()) (*target())(req, res);
}
bool abstract_server::has_target() const
{
    return m_target;
}
void abstract_server::set_address(const std::string& a)
{
    m_address = a;
}
void abstract_server::set_port(int p)
{
    m_port = p;
}
void abstract_server::set_target(const controller::ptr& t)
{
    m_target = t;
}
void abstract_server::start()
{
    if (stopped()) {
        connector::start();
        if (helper()) helper()->start();
    }
}
void abstract_server::stop()
{
    if (started()) {
        if (helper()) helper()->stop();
        connector::stop();
    }
}
}
}

