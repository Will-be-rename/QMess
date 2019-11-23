#include "disconnectionhandler.h"
#include "Data/datasrorage.h"
#include "models.h"

DisconnectionHandler::DisconnectionHandler(QObject *parent) : QObject(parent)
{

}

void DisconnectionHandler::setUser(UserStatus user)
{
    m_user = user;
}

void DisconnectionHandler::run()
{
    qDebug() << "Client disconnected slot";
    QByteArray data;
    QDataStream ds(&data, QIODevice::ReadWrite);
    ds.setVersion(QDataStream::Qt_5_11);
    ds << eUserStatus <<  m_user;
    qDebug() << "QByteArray size " << data.size();

    emit finish(data);
}
