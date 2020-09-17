#include "disconnectionhandler.h"

DisconnectionHandler::DisconnectionHandler(QObject *parent) : QObject(parent)
{

}

void DisconnectionHandler::setUser(UserStatus user)
{
    m_user = user;
}

void DisconnectionHandler::run()
{
    QByteArray data;
    QDataStream ds(&data, QIODevice::ReadWrite);
    ds.setVersion(QDataStream::Qt_5_11);
    ds << eUserStatus <<  m_user;

    emit finish(data);
}
