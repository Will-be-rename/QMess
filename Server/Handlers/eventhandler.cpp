#include "eventhandler.h"
#include "Data/datasrorage.h"

EventHandler::EventHandler(QObject *parent) : QObject(parent)
{

}

void EventHandler::handleHistoryRequest()
{

}

void EventHandler::handleMessage(Message data)
{
    for(int i = 0; i < DataStorage::getInstance()->getSessionClients().size();i++)
    {
        if(data.m_idReceiver ==
                DataStorage::getInstance()->getSessionClients()[i]->getUserStatus().m_userId)
        {
            QByteArray bytes;
            QDataStream ds(&bytes, QIODevice::ReadWrite);
            ds.setVersion(QDataStream::Qt_5_11);
            ds << eMessage <<  data;
            emit finished(DataStorage::getInstance()->getSessionClients()[i]->GetSocket(), bytes);
        }
    }
}

void EventHandler::handleUserStatus(UserStatus data)
{

}
