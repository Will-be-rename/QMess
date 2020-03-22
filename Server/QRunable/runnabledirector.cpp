#include "runnabledirector.h"
#include "models.h"
#include "Handlers/eventhandler.h"
#include "DataProviders/idataprovider.h"
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
        ds >> m_CurrentMessage;

        switch(m_CurrentMessage)
        {
            case eMessage:
            {
                Message incommingMess;
                ds >> incommingMess;
                static int messageId = 0;
                messageId++;
                incommingMess.m_idMessage = messageId;
                handler.handleMessage(incommingMess);
                qDebug() << "RunnableDirector::run() eMessage\n";
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
                emit currentUserRequest();
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

