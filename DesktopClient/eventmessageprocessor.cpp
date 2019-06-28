#include "eventmessageprocessor.h"
#include "tcpdefines.h"

#include <QHostAddress>
#include <QDebug>


EventMessageProcessor::EventMessageProcessor(QObject *parent) :
    QObject(parent),
    m_socket(),
    m_dataProvider()
{
}

void EventMessageProcessor::processEvents()
{
    // this method will receive new TCP packages
    m_socket.connectToHost(QHostAddress(tcpdefines::ip), tcpdefines::port);
    connect(&m_socket, SIGNAL(readyRead()), this, SLOT(notify()));
}

// this method will send new message to server
void EventMessageProcessor::sendMessage(const Message& newMessage)
{
    m_dataProvider.sendMessage(m_socket, newMessage);
}

// this method will send new status to server
void EventMessageProcessor::sendUserStatus(const UserStatus& newStatus)
{
    m_dataProvider.sendUserStatus(m_socket, newStatus);
}

// notify subs about new incomming TCP packages
void EventMessageProcessor::notify()
{
    int m_CurrentMessage = eMessage;
    QByteArray data = m_socket.readAll();

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
                DataStorage::getInstance().addMessage(incommingMess);
                emit newMessageRecieved();
            }
            break;

            case eUserStatus:
            {
                UserStatus userStat;
                ds >> userStat;
                DataStorage::getInstance().addUserStatus(userStat);
                emit userStatusChanged();
            }
            break;

            case  eMessageHistoryResponse:
            {
                size_t userId;
                ds >> userId;
                QVector<QString> historyData;
                ds >> historyData;
                m_cachedHistory.fillChatHistoty(userId, historyData);
                emit chatHistoryUpdated(userId);
            }
            break;
            case  eMessageHistoryRequest:
            default:
            break;
        };
    }
}
