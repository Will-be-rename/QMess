#include "serverrunner.h"
#include "message.h"

#include <QDebug>
#include <QTcpSocket>
#include <QByteArray>

ServerRunner::ServerRunner()
{
    m_server.listen(QHostAddress::Any, 18653);
    connect(&m_server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
        qDebug() << "ServerRunner ctor \n";
}

void ServerRunner::onNewConnection()
{
    QTcpSocket *clientSocket = m_server.nextPendingConnection();
    Message msg;
    msg.m_dateTime = "25.06.2019 10:43";
    msg.m_idMessage = 1;
    msg.m_idReceiver = 1;
    msg.m_idSender = 2;
    msg.m_textBody = "text";
    QByteArray data;
    QDataStream ds(&data, QIODevice::ReadWrite);
    qDebug() << "QByteArray size " << data.size();
    ds.setVersion(QDataStream::Qt_5_11);
    ds << (int)1<<  msg;
    qDebug() << "Data QByteArray|" << data.data() << "|size " << data.size();
    clientSocket->write(data);
}

