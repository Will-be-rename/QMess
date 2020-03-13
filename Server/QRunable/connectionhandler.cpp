#include "connectionhandler.h"
#include "models.h"

#include <QDebug>
#include <QThread>

ConnectionHandler::ConnectionHandler(QObject *parent) : QObject(parent)
{
}

void ConnectionHandler::run()
{
    qDebug() << "Thread id" << QThread::currentThreadId();
    static int newUserId = 0;
    newUserId++;
    UserStatus newUser {
        static_cast<int>(newUserId),
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
