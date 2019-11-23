#include "connectionhandler.h"
#include "models.h"
#include "Data/datasrorage.h"

#include <QDebug>
#include <QThread>

ConnectionHandler::ConnectionHandler(QObject *parent) : QObject(parent)
{

}

void ConnectionHandler::run()
{
    qDebug() << "Thread id" << QThread::currentThreadId();
    UserStatus newUser {
        static_cast<size_t>(DataStorage::getInstance()->getSessionClients().size()+1),
        "User "+ QString::number(DataStorage::getInstance()->getSessionClients().size()+1),
        true};

    QByteArray data;
    QDataStream ds(&data, QIODevice::ReadWrite);
    ds.setVersion(QDataStream::Qt_5_11);
    ds << eUserStatus<<  newUser;
    qDebug() << "QByteArray size " << data.size();

    qDebug() << "Client connected slot size " << DataStorage::getInstance()->getSessionClients().size();
    emit finish(data);

}
