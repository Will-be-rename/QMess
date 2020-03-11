#include "runnabledirector.h"
#include "models.h"
#include "Handlers/eventhandler.h"
#include "DataProviders/idataprovider.h"
#include <QDataStream>

RunnableDirector::RunnableDirector(QObject *parent) : QObject(parent), socket(nullptr)
{

}

void RunnableDirector::setSocket(QAbstractSocket *socket)
{
    this->socket = socket;
}

void RunnableDirector::run()
{
    if(socket != nullptr)
    {
        int m_CurrentMessage = eMessage;
        QByteArray data = socket->readAll();

        qDebug() << "TcpDataProvider::getData size " << data.size();
        QDataStream ds(&data, QIODevice::ReadWrite);
        ds.setVersion(QDataStream::Qt_5_11);
        EventHandler handler;
        while(!ds.atEnd())
        {
            ds >> m_CurrentMessage;

            switch(m_CurrentMessage)
            {
                case eMessage:
                {
                    Message incommingMess;
                    ds >> incommingMess;
                    handler.handleMessage(incommingMess);
                }
                break;

                case eUserStatus:
                {
                    UserStatus userStat;
                    ds >> userStat;

                    handler.handleUserStatus(userStat);
                }
                break;

                case eCurrentUserRequest:
                {
                    emit currentUserRequest();
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
                break;
            }
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

