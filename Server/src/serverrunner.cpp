#include "serverrunner.h"
#include "tcpdefinesAPI.h"

#include <QDebug>
#include <QTcpSocket>
#include <QByteArray>


ServerRunner::ServerRunner(commands::IWorker& worker, IDataProvider& dataprovider):
    m_worker(worker),
    m_dataprovider(dataprovider)
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

    connect(client,SIGNAL(notifyUser(QByteArray, int)),
                this, SLOT(notify(QByteArray, int)));

    connect(client,SIGNAL(userReady(SessionClient*)),
                this, SLOT(addConnection(SessionClient*)));

    client->SetSocket(handle);
}

void ServerRunner::notifyEveryone(QByteArray bytes)
{
    for(auto item : m_clients)
    {
        qDebug() << "notifyEveryone " << item->getUserStatus().m_userId << "\n";
        if(item->getUserStatus().m_userId != static_cast<int>(-1))
        {
            item->GetSocket()->write(bytes);
        }
    }
}

void ServerRunner::notify(QByteArray bytes, int clientId)
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

