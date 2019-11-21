#include "sessionclient.h"

#include <QDebug>
#include <QThreadPool>
#include <QString>
#include <QVector>

#include "models.h"
SessionClient::SessionClient(QObject *parent) : QObject(parent)
{
    qDebug() << "SessionClient ctor";
    QThreadPool::globalInstance()->setMaxThreadCount(8);
}

void SessionClient::SetSocket(qintptr handle)
{
    m_socket = new QTcpSocket(this);
    m_socket->setSocketDescriptor(handle);
    connect(m_socket,SIGNAL(connected()),   this, SLOT(connected()),    Qt::ConnectionType::AutoConnection);
    connect(m_socket,SIGNAL(disconnected()),this, SLOT(disconnected()), Qt::ConnectionType::AutoConnection);
    connect(m_socket,SIGNAL(readyRead()),   this, SLOT(readyRead()),    Qt::ConnectionType::AutoConnection);
    qDebug() << "Client connected";
}

void SessionClient::connected()
{
    clients.push_back(this);
    UserStatus newUser {
        static_cast<size_t>(clients.size()+1),
        "User "+ QString::number(clients.size()+1),
        true};


    QByteArray data;
    QDataStream ds(&data, QIODevice::ReadWrite);
    ds.setVersion(QDataStream::Qt_5_11);
    ds << eUserStatus<<  newUser;
    qDebug() << "QByteArray size " << data.size();

    qDebug() << "Client connected slot";
    for(int i = 0; i < clients.size(); i++)
    {
        if(clients[i]->m_socket != nullptr)
        {
            clients[i]->m_socket->write(data);
        }
    }

}

void SessionClient::disconnected()
{
    qDebug() << "Client disconnected slot";
    UserStatus newUser {
        static_cast<size_t>(clients.size()+1),
        "User "+ QString::number(clients.size()+1),
        false};


    QByteArray data;
    QDataStream ds(&data, QIODevice::ReadWrite);
    ds.setVersion(QDataStream::Qt_5_11);
    ds << eUserStatus<<  newUser;
    qDebug() << "QByteArray size " << data.size();

    qDebug() << "Client connected slot";
    for(int i = 0; i < clients.size(); i++)
    {
        if(clients[i]->m_socket != nullptr)
        {
            clients[i]->m_socket->write(data);
        }
    }
}

void SessionClient::readyRead()
{
    qDebug() << "readyRead " << m_socket->readAll();
    RunnableDirector* director = new RunnableDirector();
    director->setAutoDelete(true);
    director->setSocket(m_socket);
    QThreadPool::globalInstance()->start(director);
}

void SessionClient::result(int Number)
{

}
