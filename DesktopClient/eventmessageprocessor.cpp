#include "eventmessageprocessor.h"

#include <QDebug>

EventMessageProcessor::EventMessageProcessor(QObject *parent) : QObject(parent), m_isRunning(true), m_CurrentMessage(eMessage)
{

}

void EventMessageProcessor::processEvents()
{
    // this method will receive new TCP packages
    notify();
    qDebug() << "Done";
}

void EventMessageProcessor::finish()
{
    m_isRunning = false;
}

// this method will send new message to server
void EventMessageProcessor::sendMessage(const Message &newMessage)
{
    throw std::exception("Not implemented !!!");
}

// this method will send new message to server
void EventMessageProcessor::login(const UserStatus &newStatus)
{
    throw std::exception("Not implemented !!!");
}

// this method will send new message to server and close tcp socket
void EventMessageProcessor::logout(const UserStatus &newStatus)
{
    throw std::exception("Not implemented !!!");
}

// notify subs about new incomming TCP packages
void EventMessageProcessor::notify()
{
    switch(m_CurrentMessage)
    {
        case eMessage:
        {
            Message mess;
            DataStorage::getInstance().addMessage(mess);
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
