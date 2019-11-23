#include "disconnectionhandler.h"
#include "Data/datasrorage.h"
#include "models.h"

DisconnectionHandler::DisconnectionHandler(QObject *parent) : QObject(parent)
{

}

void DisconnectionHandler::run()
{
    qDebug() << "Client disconnected slot";
    UserStatus newUser {
        static_cast<size_t>(DataStorage::getInstance()->getSessionClients().size()+1),
        "User "+ QString::number(DataStorage::getInstance()->getSessionClients().size()+1),
        false};


    QByteArray data;
    QDataStream ds(&data, QIODevice::ReadWrite);
    ds.setVersion(QDataStream::Qt_5_11);
    ds << eUserStatus<<  newUser;
    qDebug() << "QByteArray size " << data.size();
    emit finish(data);
}
