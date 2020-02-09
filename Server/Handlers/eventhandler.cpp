#include "eventhandler.h"

EventHandler::EventHandler(QObject *parent) : QObject(parent)
{

}

void EventHandler::handleHistoryRequest()
{

}

void EventHandler::handleMessage(Message data)
{    
    QByteArray bytes;
    QDataStream ds(&bytes, QIODevice::ReadWrite);
    ds.setVersion(QDataStream::Qt_5_11);
    ds << eMessage <<  data;
    emit notifyReciever(bytes, data.m_idReceiver);
    emit notifySender(bytes, data.m_idSender);
}

void EventHandler::handleUserStatus(UserStatus data)
{

}
