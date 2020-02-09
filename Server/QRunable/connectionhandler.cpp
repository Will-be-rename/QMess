#include "connectionhandler.h"
#include "models.h"

#include <ctime>
#include <cstdlib>

#include <QDebug>
#include <QThread>

ConnectionHandler::ConnectionHandler(QObject *parent) : QObject(parent)
{
    srand(time(NULL));
}

void ConnectionHandler::run()
{
    qDebug() << "Thread id" << QThread::currentThreadId();
    size_t newUserId = rand() % 1000;
    UserStatus newUser {
        static_cast<size_t>(newUserId),
        "User "+ QString::number(newUserId),
        true};
    emit userFound(newUser.m_userId, newUser.m_userName, newUser.m_isOnline);
    QByteArray data;
    QDataStream ds(&data, QIODevice::ReadWrite);
    ds.setVersion(QDataStream::Qt_5_11);
    ds << eUserStatus<<  newUser;
    qDebug() << "QByteArray size " << data.size();

    qDebug() << "Client connected slot size " << newUserId;
    emit finish(data);

}
