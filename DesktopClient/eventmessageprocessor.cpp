#include "eventmessageprocessor.h"

#include <QHostAddress>
#include <QDebug>

EventMessageProcessor::EventMessageProcessor(QObject *parent) :
    QObject(parent),
    m_isRunning(true),
    m_socket()
{
    m_socket.connectToHost(QHostAddress("127.0.0.1"), 18653);
    connect(&m_socket, SIGNAL(readyRead()), this, SLOT(notify()));
}

void EventMessageProcessor::processEvents()
{
    // this method will receive new TCP packages

}

void EventMessageProcessor::finish()
{
    m_isRunning = false;
}

// this method will send new message to server
void EventMessageProcessor::sendMessage(const Message &newMessage)
{
    throw std::exception();
}

// this method will send new message to server
void EventMessageProcessor::login(const UserStatus &newStatus)
{
    throw std::exception();
}

// this method will send new message to server and close tcp socket
void EventMessageProcessor::logout(const UserStatus &newStatus)
{
    throw std::exception();
}

// notify subs about new incomming TCP packages
void EventMessageProcessor::notify()
{
    Message incommingMess;
    QByteArray data = m_socket.readAll();
    QDataStream ds(&data, QIODevice::ReadWrite);
    ds.setVersion(QDataStream::Qt_5_11);
    ds >> incommingMess;
    qDebug() << data;
    qDebug() << "incommingMess "  << incommingMess.m_dateTime << "  " << incommingMess.m_textBody;
    auto m_CurrentMessage = eMessage;
    switch(m_CurrentMessage)
    {
        case eMessage:
        {
            DataStorage::getInstance().addMessage(incommingMess);
            emit newMessageRecieved();
        }
        break;

        case eUserStatus:
        {
            UserStatus userStat;
            DataStorage::getInstance().addUserStatus(userStat);
            emit userStatusChanged();
        }
        break;

        default:
        break;
    };
}
