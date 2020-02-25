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
}

void EventMessageProcessor::processEvents()
{
    // this method will receive new TCP packages
    connect(&m_socket, SIGNAL(readyRead()), this, SLOT(notify()));
    m_socket.connectToHost(QHostAddress(tcpdefines::ip), tcpdefines::port);
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
    m_dataProvider.getData(m_socket);
}

TcpDataProvider& EventMessageProcessor::dataProvider()
{
    return m_dataProvider;
}

