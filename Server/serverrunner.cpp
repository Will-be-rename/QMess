#include "serverrunner.h"
#include "models.h"
#include "tcpdefines.h"


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

    connect(client,SIGNAL(notifyEveryoneSignal(QByteArray)),
                this, SLOT(notifyEveryone(QByteArray)));

    connect(client,SIGNAL(notifyUserSlot(QByteArray, size_t)),
                this, SLOT(notify(QByteArray, size_t)));

    connect(client,SIGNAL(userReady(SessionClient*)),
                this, SLOT(addConnection(SessionClient*)));

    client->SetSocket(handle);
}

void ServerRunner::notifyEveryone(QByteArray bytes)
{
    for(auto item : m_clients)
    {
        if(item->getUserStatus().m_userId == static_cast<size_t>(-1))
        {
            item->GetSocket()->write(bytes);
        }
    }
}

void ServerRunner::notify(QByteArray bytes, size_t clientId)
{
    for(auto item : m_clients)
    {
        if(item->getUserStatus().m_userId == clientId)
        {
            item->GetSocket()->write(bytes);
        }
    }
}

void ServerRunner::addConnection(SessionClient* connection)
{
    for(auto item : m_clients)
    {
        connection->GetSocket()->write(item->getUserStatusBytes());
    }
    m_clients.push_back(connection);
}

