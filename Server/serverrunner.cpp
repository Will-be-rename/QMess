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

    connect(client,SIGNAL(notifyReciever(QByteArray, size_t)),
                this, SLOT(notify(QByteArray, size_t)));

    connect(client,SIGNAL(notifySender(QByteArray, size_t)),
                this, SLOT(notify(QByteArray, size_t)));

    client->SetSocket(handle);
    m_clients.push_back(client);

}

void ServerRunner::notifyEveryone(QByteArray bytes)
{
    for(auto item : m_clients)
    {
        item->GetSocket()->write(bytes);
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

