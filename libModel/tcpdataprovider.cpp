#include "tcpdataprovider.h"

void TcpDataProvider::sendMessage(QTcpSocket &socket, const Message &message)
{
    QByteArray data;
    QDataStream ds(&data, QIODevice::ReadWrite);
    ds.setVersion(QDataStream::Qt_5_11);
    ds << static_cast<int>(eMessage) << message;
    socket.write(data);
}

void TcpDataProvider::sendUserStatus(QTcpSocket &socket, const UserStatus &userStatus)
{
    QByteArray data;
    QDataStream ds(&data, QIODevice::ReadWrite);
    ds.setVersion(QDataStream::Qt_5_11);
    ds << static_cast<int>(eUserStatus) << userStatus;
    socket.write(data);
}

void TcpDataProvider::sendLoginPackage(QTcpSocket &socket, const UserStatus &loginData)
{
    QByteArray data;
    QDataStream ds(&data, QIODevice::ReadWrite);
    ds.setVersion(QDataStream::Qt_5_11);
    ds << static_cast<int>(eCurrentUserRequest) << loginData;
    socket.write(data);
}

void TcpDataProvider::sendMessageHistoryRequest(QTcpSocket& socket, const HistoryData& history)
{
    QByteArray data;
    QDataStream ds(&data, QIODevice::ReadWrite);
    ds.setVersion(QDataStream::Qt_5_11);
    ds << static_cast<int>(eMessageHistoryRequest) << history;
    socket.write(data);
}

void TcpDataProvider::getData(QTcpSocket &socket)
{
    int m_CurrentMessage = eMessage;
    QByteArray data = socket.readAll();

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
