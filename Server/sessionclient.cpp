#include "sessionclient.h"

#include <QDebug>
#include <QThreadPool>
#include <QString>
#include <QVector>
#include <QMutex>

#include "models.h"
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

    emit notifyEveryoneSignal(data);
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

void SessionClient::setUserStatus(size_t      m_userId,
                                  QString     m_userName,
                                  bool        m_isOnline)
{
    UserStatus newUser{m_userId, m_userName, m_isOnline};
    m_user = newUser;
}

void SessionClient::notifyRecieverSlot(QByteArray data, size_t recieverId)
{
    // provide signal to upper level
    emit notifyReciever(data, recieverId);
}

void SessionClient::notifySenderSlot(QByteArray data, size_t senderId)
{
    // provide signal to upper level
    emit notifySender(data, senderId);
}

UserStatus SessionClient::getUserStatus()
{
    return m_user;
}

bool SessionClient::operator==(const SessionClient &other)
{
    bool result = false;
    if(other.m_user.m_userId == this->m_user.m_userId)
    {
        result = true;
    }
    return result;
}

void SessionClient::setUpUser()
{
    ConnectionHandler* handler = new ConnectionHandler();
    handler->setAutoDelete(true);
    connect(handler,SIGNAL(finish(QByteArray)),             this, SLOT(notifyEveryone(QByteArray)),         Qt::ConnectionType::QueuedConnection);
    connect(handler,SIGNAL(userFound(size_t,QString,bool)), this, SLOT(setUserStatus(size_t,QString,bool)), Qt::ConnectionType::QueuedConnection);
    QThreadPool::globalInstance()->start(handler);

    SetUpUserHandler* setUpHandler = new SetUpUserHandler();
    setUpHandler->setAutoDelete(true);
    setUpHandler->setSession(this);
    connect(setUpHandler,SIGNAL(finish(QTcpSocket *, QByteArray)),   this, SLOT(sendData(QTcpSocket *, QByteArray)), Qt::ConnectionType::QueuedConnection);
    QThreadPool::globalInstance()->start(setUpHandler);
}
