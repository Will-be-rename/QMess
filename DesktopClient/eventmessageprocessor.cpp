#include "eventmessageprocessor.h"

#include <QDebug>

EventMessageProcessor::EventMessageProcessor(QObject *parent) : QObject(parent), m_isRunning(true), m_CurrentMessage(eMessage)
{

}

void EventMessageProcessor::processEvents()
{
    notify();
    qDebug() << "Done";
}

void EventMessageProcessor::finish()
{
    m_isRunning = false;
}

void EventMessageProcessor::sendMessage(const Message &newMessage)
{
    throw std::exception("Not implemented !!!");
}

void EventMessageProcessor::login(const UserStatus &newStatus)
{
    throw std::exception("Not implemented !!!");
}

void EventMessageProcessor::logout(const UserStatus &newStatus)
{
    throw std::exception("Not implemented !!!");
}

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
