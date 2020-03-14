#include "eventmessageprocessor.h"
#include "tcpdefines.h"

#include <QHostAddress>
#include <QDebug>


EventMessageProcessor::EventMessageProcessor(QObject *parent) :
    QObject(parent),
    m_socket(this),
    m_dataProvider()
{
    DataStorage* pointer = &DataStorage::getInstance();
    connect(&m_dataProvider, SIGNAL(currentUserDetected(UserStatus)),
            pointer, SLOT(setCurrentUser(UserStatus)) );
    connect(&m_dataProvider, SIGNAL(newUserStatusDetected(UserStatus)),
                     this, SLOT(newUserStatusDetectedSlot(UserStatus)));
    connect(&m_dataProvider, SIGNAL(newMessageDetected(Message)),
                     this, SLOT(newMessageDetectedSlot(Message)));
}

void EventMessageProcessor::processEvents()
{
    // this method will receive new TCP packages
    connect(&m_socket, SIGNAL(readyRead()), this, SLOT(notify()));
    connect(&m_socket, SIGNAL(connected()), this, SLOT(clientConnected()));
    m_socket.connectToHost(QHostAddress(tcpdefines::ip), tcpdefines::port);
}

// this method will send new message to server
void EventMessageProcessor::sendMessage(const MessageView& newMessage)
{
    Message messageToSend;
    messageToSend.m_textBody = newMessage.getTextBody();
    messageToSend.m_idReceiver = newMessage.getChatId();
    messageToSend.m_dateTime = QDateTime::currentDateTime().toString();
    messageToSend.m_idSender = DataStorage::getInstance().getCurrentUser().m_userId;
    qDebug() <<"EventMessageProcessor::sendMessage";
    m_dataProvider.sendMessage(m_socket, messageToSend);
}

// this method will send new status to server
void EventMessageProcessor::sendUserStatus(const UserStatus& newStatus)
{
    m_dataProvider.sendUserStatus(m_socket, newStatus);
}

// notify subs about new incomming TCP packages
void EventMessageProcessor::notify()
{
    m_dataProvider.getData(m_socket);
}

TcpDataProvider& EventMessageProcessor::dataProvider()
{
    return m_dataProvider;
}

void EventMessageProcessor::clientConnected()
{
    LoginPackage login{"",""};
    m_dataProvider.sendLoginPackage(m_socket, login);
}

void EventMessageProcessor::newUserStatusDetectedSlot(const UserStatus& newStatus)
{
    if(newStatus.m_userId != DataStorage::getInstance().getCurrentUser().m_userId)
    {
        User newUser(newStatus.m_userId, newStatus.m_userName, newStatus.m_isOnline);
        emit newUserDetected(newUser);
    }
}

void EventMessageProcessor::newMessageDetectedSlot(const Message& newMessage)
{
    MessageView newMess(newMessage.m_textBody, newMessage.m_dateTime, newMessage.m_idSender);
    qDebug() <<"EventMessageProcessor::newMessageDetectedSlot";
    emit newMessageReceived(newMess);
}

