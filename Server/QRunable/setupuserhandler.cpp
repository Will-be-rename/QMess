#include "setupuserhandler.h"
#include "models.h"
#include "Data/datasrorage.h"

SetUpUserHandler::SetUpUserHandler(QObject *parent) : QObject(parent)
{

}

void SetUpUserHandler::setSession(SessionClient* session)
{
    m_session = session;
}

void SetUpUserHandler::run()
{
    for(int i = 0; i < DataStorage::getInstance()->getSessionClients().size(); i++)
    {
        if(m_session != DataStorage::getInstance()->getSessionClients()[i])
        {
            UserStatus status = DataStorage::getInstance()->getSessionClients()[i]->getUserStatus();

            QByteArray data;
            QDataStream ds(&data, QIODevice::ReadWrite);
            ds.setVersion(QDataStream::Qt_5_11);
            ds << eUserStatus<<  status;
            qDebug() << "setUpUserHandler QByteArray size " << data.size();

            emit finish(m_session->GetSocket(), data);
        }
    }
}
