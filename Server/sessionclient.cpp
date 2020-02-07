#include "sessionclient.h"

#include <QDebug>
#include <QThreadPool>
#include <QString>
#include <QVector>
#include <QMutex>

#include "models.h"
#include "Data/datasrorage.h"
#include "QRunable/connectionhandler.h"
#include "QRunable/disconnectionhandler.h"
#include "QRunable/setupuserhandler.h"
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

    setUpUser();
}

QTcpSocket *SessionClient::GetSocket()
{
    return m_socket;
}

void SessionClient::disconnected()
{
    DisconnectionHandler* handler = new DisconnectionHandler();
    handler->setAutoDelete(true);
    m_user.m_isOnline = false;
    handler->setUser(m_user);
    QThreadPool::globalInstance()->start(handler);
    connect(handler,SIGNAL(finish(QByteArray)),   this, SLOT(notifyEveryone(QByteArray)),    Qt::ConnectionType::QueuedConnection);
}

void SessionClient::readyRead()
{
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

void SessionClient::sendData(QTcpSocket *socket, QByteArray data)
{
    if(socket != nullptr &&
       socket->state() == QAbstractSocket::SocketState::ConnectedState)
    {
        socket->write(data);
    }
}

void SessionClient::setUserStatus(UserStatus newUser)
{
    m_user = newUser;
}

UserStatus SessionClient::getUserStatus()
{
    return m_user;
}

void SessionClient::setUpUser()
{
    ConnectionHandler* handler = new ConnectionHandler();
    handler->setAutoDelete(true);
    connect(handler,SIGNAL(finish(QByteArray)),   this, SLOT(notifyEveryone(QByteArray)), Qt::ConnectionType::QueuedConnection);
    connect(handler,SIGNAL(userFound(UserStatus)),this, SLOT(setUserStatus(UserStatus)),  Qt::ConnectionType::QueuedConnection);
    QThreadPool::globalInstance()->start(handler);

    DataStorage::getInstance()->getSessionClients().push_back(this);
    SetUpUserHandler* setUpHandler = new SetUpUserHandler();
    setUpHandler->setAutoDelete(true);
    setUpHandler->setSession(this);
    connect(setUpHandler,SIGNAL(finish(QTcpSocket *, QByteArray)),   this, SLOT(sendData(QTcpSocket *, QByteArray)), Qt::ConnectionType::QueuedConnection);
    QThreadPool::globalInstance()->start(setUpHandler);
}
