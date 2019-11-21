#include "serverrunner.h"
#include "models.h"
#include "tcpdefines.h"
#include "sessionclient.h"

#include <QDebug>
#include <QTcpSocket>
#include <QByteArray>


ServerRunner::ServerRunner()
{
    qDebug() << "ServerRunner ctor \n";
}

void ServerRunner::StartServer()
{
    if(listen(QHostAddress::Any, tcpdefines::port))
    {
        qDebug() << "Server already started";
    }
    else
    {
        qDebug() << "Server not started";
    }
}

void ServerRunner::incomingConnection(qintptr handle)
{
    qDebug() << "incomingConnection";
    SessionClient* client = new SessionClient(this);
    client->SetSocket(handle);
}

