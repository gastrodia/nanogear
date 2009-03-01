/*
 * Nanogear - C++ web development framework
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

#include <QDebug>
#include <QCoreApplication>
#include <QHttpResponseHeader>
#include <QHttpRequestHeader>
#include <QTcpSocket>

#include "application.h"
#include "server.h"
#include "httpserver.h"
#include "resource.h"
#include "router.h"

class RootResource : public Resource {
    virtual void handleGet() {
        qDebug() << "Called RootResource::handleGet()";
    }
};

class SimpleApplication : public Application {
    virtual Router* createRoot() {
        Router* r = new Router(context());
        r->attach("/resource", new RootResource());
        return r;
    }
};

int main(int argc, char** argv) {
    QCoreApplication app(argc, argv);
    
    Server* server = new HTTPServer(8080);
    server->attach("/simple", new SimpleApplication());
    server->start();
    
    return app.exec();
}