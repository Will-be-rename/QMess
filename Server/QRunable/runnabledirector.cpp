#include "runnabledirector.h"
#include "models.h"
#include "Handlers/eventhandler.h"
#include "DataProviders/mockdataprovider.h"
#include <QDataStream>

RunnableDirector::RunnableDirector(QAbstractSocket *_socket, QObject *parent) : QObject(parent), socket(_socket)
{

}

void RunnableDirector::run()
{
    int m_CurrentMessage = eMessage;
    QByteArray data = socket->readAll();

    qDebug() << "TcpDataProvider::getData size " << data.size();
    QDataStream ds(&data, QIODevice::ReadWrite);
    ds.setVersion(QDataStream::Qt_5_11);
    EventHandler handler;
    connect(&handler,SIGNAL(notifyReciever(QByteArray, int)),    this, SLOT(notifyRecieverProvider(QByteArray, int)),     Qt::ConnectionType::QueuedConnection);
    connect(&handler,SIGNAL(notifySender(QByteArray, int)),      this, SLOT(notifySenderProvider(QByteArray, int)),     Qt::ConnectionType::QueuedConnection);
    while(!ds.atEnd())
    {
        qDebug() << "RunnableDirector::run() while\n";
        ds >> m_CurrentMessage;
        MockDataProvider provider;
        switch(m_CurrentMessage)
        {
            case eMessage:
            {
                qDebug() << "RunnableDirector::run() start eMessage\n";
                Message incommingMess;
                ds >> incommingMess;
                provider.createMessageId(incommingMess);
                provider.addToHistory(incommingMess);
                handler.handleMessage(incommingMess);
                qDebug() << "RunnableDirector::run() end eMessage\n";
            }
            break;

            case eUserStatus:
            {
                UserStatus userStat;
                ds >> userStat;

                handler.handleUserStatus(userStat);
                qDebug() << "RunnableDirector::run() eUserStatus\n";
            }
            break;

            case eCurrentUserRequest:
            {
                UserStatus usr = provider.getUserData(LoginPackage{});
                emit currentUserRequest(usr.m_userId,usr.m_userName,usr.m_isOnline);

                QByteArray data;
                QDataStream ds(&data, QIODevice::ReadWrite);
                ds.setVersion(QDataStream::Qt_5_11);
                ds << eUserStatus<<  usr;
                emit notifyEveryone(data);

                qDebug() << "RunnableDirector::run() eCurrentUserRequest\n";

            }
            break;
            case  eMessageHistoryRequest:
            {
                /*IDataProvider* provider = nullptr;
                UserStatus userStat;
                ds >> userStat;
                provider->getHistory();*/
            }
            break;
            default:
            qDebug() << "RunnableDirector::run() default\n";
            break;
        }
    }
}

void RunnableDirector::notifyRecieverProvider(QByteArray data, int recieverId)
{
    emit notifyReciever(data, recieverId);
}

void RunnableDirector::notifySenderProvider(QByteArray data, int senderId)
{
    emit notifySender(data, senderId);
}

