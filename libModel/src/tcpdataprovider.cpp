#include "tcpdataprovider.h"

TcpDataProvider::TcpDataProvider(QTcpSocket* socket):
                                 m_socket(socket)
{}

void TcpDataProvider::sendData(const Message &message)
{
    QByteArray data;
    QDataStream ds(&data, QIODevice::ReadWrite);
    ds.setVersion(QDataStream::Qt_5_11);
    ds << static_cast<int>(eMessage) << message;
    m_socket->write(data);
}

void TcpDataProvider::sendData(const UserStatus &userStatus)
{
    QByteArray data;
    QDataStream ds(&data, QIODevice::ReadWrite);
    ds.setVersion(QDataStream::Qt_5_11);
    ds << static_cast<int>(eUserStatus) << userStatus;
    m_socket->write(data);
}

void TcpDataProvider::sendData(const LoginPackage& loginpackge)
{
    QByteArray data;
    QDataStream ds(&data, QIODevice::ReadWrite);
    ds.setVersion(QDataStream::Qt_5_11);
    ds << static_cast<int>(eCurrentUserRequest) << loginpackge;
    m_socket->write(data);
}

void TcpDataProvider::sendData(const HistoryDataRequest& history)
{
    QByteArray data;
    QDataStream ds(&data, QIODevice::ReadWrite);
    ds.setVersion(QDataStream::Qt_5_11);
    ds << static_cast<int>(eMessageHistoryRequest) << history;
    m_socket->write(data);
}

void TcpDataProvider::getData()
{
    int m_CurrentMessage = eMessage;
    QByteArray data = m_socket->readAll();

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
                emit newMessageDetected(incommingMess);
            }
            break;

            case eUserStatus:
            {
                UserStatus userStat;
                ds >> userStat;
                emit newUserStatusDetected(userStat);
            }
            break;

            case  eMessageHistoryResponse:
            {
                HistoryData historyData;
                ds >> historyData;
                //save for future
                //m_cachedHistory.fillChatHistoty(userId, historyData);
                emit chatHistoryUpdated(historyData);
            }
            break;
            case eCurrentUserResponse:
            {
                UserStatus userStat;
                ds >> userStat;
                emit currentUserDetected(userStat);
            }
            break;
            case  eMessageHistoryRequest:
            default:
            break;
        }
    }
}
