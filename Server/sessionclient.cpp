#include "sessionclient.h"

#include <QDebug>
#include <QThreadPool>
#include <QString>
#include <QVector>
#include <QMutex>

#include "models.h"
#include "Data/datasrorage.h"
#include "QRunable/connectionhandler.h"
SessionClient::SessionClient(QObject *parent) : QObject(parent)
{
    qDebug() << "SessionClient ctor";
    QThreadPool::globalInstance()->setMaxThreadCount(8);
}

void SessionClient::SetSocket(qintptr handle)
{
    m_socket = new QTcpSocket(this);
    m_socket->setSocketDescriptor(handle);
    connect(m_socket,SIGNAL(disconnected()),this, SLOT(disconnected()), Qt::ConnectionType::AutoConnection);
    connect(m_socket,SIGNAL(readyRead()),   this, SLOT(readyRead()),    Qt::ConnectionType::AutoConnection);


    qDebug() << "Client connected" << "Thread id" << QThread::currentThreadId();

    ConnectionHandler* director = new ConnectionHandler();
    director->setAutoDelete(true);
    QThreadPool::globalInstance()->start(director);
    connect(director,SIGNAL(finish(QByteArray)),   this, SLOT(notifyEveryone(QByteArray)),    Qt::ConnectionType::QueuedConnection);

    DataStorage::getInstance()->getSessionClients().push_back(this);
}

QTcpSocket *SessionClient::GetSocket()
{
    return m_socket;
}

void SessionClient::disconnected()
{
    qDebug() << "Client disconnected slot";
    UserStatus newUser {
        static_cast<size_t>(DataStorage::getInstance()->getSessionClients().size()+1),
        "User "+ QString::number(DataStorage::getInstance()->getSessionClients().size()+1),
        false};


    QByteArray data;
    QDataStream ds(&data, QIODevice::ReadWrite);
    ds.setVersion(QDataStream::Qt_5_11);
    ds << eUserStatus<<  newUser;
    qDebug() << "QByteArray size " << data.size();
    for(int i = 0; i < DataStorage::getInstance()->getSessionClients().size(); i++)
    {
        if(DataStorage::getInstance()->getSessionClients()[i]->m_socket != nullptr)
        {
            DataStorage::getInstance()->getSessionClients()[i]->m_socket->write(data);
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

void SessionClient::notifyEveryone(QByteArray data)
{
    qDebug() << "notifyEveryone Thread id" << QThread::currentThreadId() << " data size: " << data.size();

    for(int i = 0; i < DataStorage::getInstance()->getSessionClients().size(); i++)
    {
        if(     (DataStorage::getInstance()->getSessionClients()[i]->m_socket != nullptr)
                &&
                (DataStorage::getInstance()->getSessionClients()[i]->m_socket->state()
                == QAbstractSocket::SocketState::ConnectedState))
        {
            DataStorage::getInstance()->getSessionClients()[i]->m_socket->write(data);
        }

    }
}
