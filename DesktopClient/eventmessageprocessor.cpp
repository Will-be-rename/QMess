#include "eventmessageprocessor.h"
#include "tcpdefines.h"

#include <QHostAddress>
#include <QDebug>


EventMessageProcessor::EventMessageProcessor(QObject *parent) :
    QObject(parent),
    m_isRunning(true),
    m_socket()
{
}

void EventMessageProcessor::processEvents()
{
    // this method will receive new TCP packages
    m_socket.connectToHost(QHostAddress(tcpdefines::ip), tcpdefines::port);
    connect(&m_socket, SIGNAL(readyRead()), this, SLOT(notify()));
}

void EventMessageProcessor::finish()
{
    m_isRunning = false;
}

// this method will send new message to server
void EventMessageProcessor::sendMessage(const Message& newMessage)
{
    QByteArray data;
    QDataStream ds(&data, QIODevice::ReadWrite);
    ds.setVersion(QDataStream::Qt_5_11);
    ds << static_cast<int>(eMessage) << newMessage;
    m_socket.write(data);
}

// this method will send new status to server
void EventMessageProcessor::sendUserStatus(const UserStatus& newStatus)
{
    QByteArray data;
    QDataStream ds(&data, QIODevice::ReadWrite);
    ds.setVersion(QDataStream::Qt_5_11);
    ds << static_cast<int>(eUserStatus) << newStatus;
    m_socket.write(data);
}

// notify subs about new incomming TCP packages
void EventMessageProcessor::notify()
{
    int m_CurrentMessage = eMessage;
    QByteArray data = m_socket.readAll();

    QDataStream ds(&data, QIODevice::ReadWrite);
    ds.setVersion(QDataStream::Qt_5_11);
    ds >> m_CurrentMessage;

    switch(m_CurrentMessage)
    {
        case eMessage:
        {
            Message incommingMess;
            ds >> incommingMess;
            DataStorage::getInstance().addMessage(incommingMess);
            emit newMessageRecieved();
        }
        break;

        case eUserStatus:
        {
            UserStatus userStat;
            ds >> userStat;
            DataStorage::getInstance().addUserStatus(userStat);
            emit userStatusChanged();
        }
        break;

        default:
        break;
    };
}
