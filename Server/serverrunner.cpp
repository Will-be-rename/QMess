#include "serverrunner.h"
#include "models.h"
#include "tcpdefines.h"

#include <QDebug>
#include <QTcpSocket>
#include <QByteArray>

#include <thread>
ServerRunner::ServerRunner()
{
    m_server.listen(QHostAddress::Any, tcpdefines::port);
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
    UserStatus usr;
    usr.m_userId = 1;
    usr.m_isOnline = true;
    usr.m_userName = "online user";
    QByteArray data;
    QDataStream ds(&data, QIODevice::ReadWrite);
    qDebug() << "QByteArray size " << data.size();
    ds.setVersion(QDataStream::Qt_5_11);
    ds << (int)0<<  usr;
    qDebug() << "Data QByteArray|" << data.data() << "|size " << data.size();
    clientSocket->write(data);

    usr.m_userId = 2;
    usr.m_isOnline = false;
    usr.m_userName = "Offline user";
    QByteArray data1;
    QDataStream ds1(&data1, QIODevice::ReadWrite);
    qDebug() << "QByteArray size " << data1.size();
    ds1.setVersion(QDataStream::Qt_5_11);
    ds1 << (int)0<<  usr;
    qDebug() << "Data QByteArray|" << data1.data() << "|size " << data1.size();
    clientSocket->write(data1);
}

