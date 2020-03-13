#include "sessionclient.h"

#include <QDebug>
#include <QThreadPool>
#include <QString>
#include <QVector>
#include <QMutex>

#include "models.h"
#include "QRunable/connectionhandler.h"
#include "QRunable/disconnectionhandler.h"
SessionClient::SessionClient(QObject *parent) : QObject(parent)
{
    qDebug() << "SessionClient ctor";
    QThreadPool::globalInstance()->setMaxThreadCount(8);
    m_user.m_userId = static_cast<int>(-1);
}

void SessionClient::SetSocket(qintptr handle)
{
    m_socket = new QTcpSocket(this);
    m_socket->setSocketDescriptor(handle);
    connect(m_socket,SIGNAL(disconnected()),this, SLOT(disconnected()), Qt::ConnectionType::AutoConnection);
    connect(m_socket,SIGNAL(readyRead()),   this, SLOT(readyRead()),    Qt::ConnectionType::AutoConnection);

}

QTcpSocket *SessionClient::GetSocket()
{
    return m_socket;
}

void SessionClient::disconnected()
{
    if(m_user.m_userId != static_cast<int>(-1))
    {
        DisconnectionHandler* handler = new DisconnectionHandler();
        handler->setAutoDelete(true);
        m_user.m_isOnline = false;
        handler->setUser(m_user);
        QThreadPool::globalInstance()->start(handler);
        connect(handler,SIGNAL(finish(QByteArray)),   this, SLOT(notifyEveryone(QByteArray)),    Qt::ConnectionType::QueuedConnection);
    }
}

void SessionClient::readyRead()
{
    RunnableDirector* director = new RunnableDirector();
    director->setAutoDelete(true);
    director->setSocket(m_socket);

    connect(director,SIGNAL(currentUserRequest()),                  this, SLOT(setUpUser()),                            Qt::ConnectionType::QueuedConnection);
    connect(director,SIGNAL(notifyReciever(QByteArray, int)),    this, SLOT(notifyUserSlot(QByteArray, int)),     Qt::ConnectionType::QueuedConnection);
    connect(director,SIGNAL(notifySender(QByteArray, int)),      this, SLOT(notifyUserSlot(QByteArray, int)),     Qt::ConnectionType::QueuedConnection);
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

void SessionClient::setUserStatus(int      m_userId,
                                  QString     m_userName,
                                  bool        m_isOnline)
{
    UserStatus newUser{m_userId, m_userName, m_isOnline};
    m_user = newUser;
    emit userReady(this);

    QByteArray data;
    QDataStream ds(&data, QIODevice::ReadWrite);
    ds.setVersion(QDataStream::Qt_5_11);
    ds << eCurrentUserResponse <<  m_user;
    m_socket->write(data);
}


void SessionClient::notifyUserSlot(QByteArray data, int userId)
{
    // provide signal to upper level
    emit notifyUser(data, userId);
}

QByteArray SessionClient::getUserStatusBytes()
{
    QByteArray data;
    QDataStream ds(&data, QIODevice::ReadWrite);
    ds.setVersion(QDataStream::Qt_5_11);
    ds << eUserStatus<<  m_user;
    return data;
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
    connect(handler,SIGNAL(userFound(int,QString,bool)), this, SLOT(setUserStatus(int,QString,bool)), Qt::ConnectionType::QueuedConnection);
    connect(handler,SIGNAL(finish(QByteArray)),             this, SLOT(notifyEveryone(QByteArray)),         Qt::ConnectionType::QueuedConnection);
    QThreadPool::globalInstance()->start(handler);

}
