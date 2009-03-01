/*
 * Nanogear - C++ web development framework
 *
 * This library is based on Restlet (R) <http://www.restlet.org> by Noelios Technologies
 * Copyright (C) 2005-2008 by Noelios Technologies <http://www.noelios.com>
 * Restlet is a registered trademark of Noelios Technologies. All other marks and
 * trademarks are property of their respective owners.
 *
 * Copyright (C) 2008-2009 Lorenzo Villani.
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

#ifndef SERVER_H
#define SERVER_H

#include <QList>

#include "context.h"

class QString;
class Application;

class Server {
public:
    Server(int port = 8080) : m_listenPort(port) {}
    virtual ~Server() {}
    
    void attach(const QString& context, Application*);
    virtual void start() = 0;

    const QList<Application*>& attachedApplications() const
        { return m_applications; }
    
    void setContext(const Context& context)
        { m_context = context; }
    const Context& context() const
        { return m_context; }

    void setListenPort(int port)
        { m_listenPort = port; }
    int listenPort() const
        { return m_listenPort; }
        
private:
    int m_listenPort;
    Context m_context;
    QList<Application*> m_applications;
};

#endif // SERVER_H