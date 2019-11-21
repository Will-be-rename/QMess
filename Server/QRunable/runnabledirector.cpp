#include "runnabledirector.h"
#include "models.h"

#include <QDataStream>

RunnableDirector::RunnableDirector() : socket(nullptr)
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
        while(!ds.atEnd())
        {
            ds >> m_CurrentMessage;

            switch(m_CurrentMessage)
            {
                case eMessage:
                {
                    Message incommingMess;
                    ds >> incommingMess;

                }
                break;

                case eUserStatus:
                {
                    UserStatus userStat;
                    ds >> userStat;

                }
                break;

                case eCurrentUserResponse:
                {
                    UserStatus userStat;
                    ds >> userStat;

                }
                break;
                case  eMessageHistoryRequest:
                default:
                break;
            }
        }
    }
}
