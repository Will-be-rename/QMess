#include "serverrunner.h"
#include "models.h"
#include "tcpdefines.h"

#include <QDebug>
#include <QTcpSocket>
#include <QByteArray>


ServerRunner::ServerRunner()
{
    this->listen(QHostAddress::Any, tcpdefines::port);
    connect(this, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
        qDebug() << "ServerRunner ctor \n";
}

void ServerRunner::onNewConnection()
{
    QTcpSocket *clientSocket = this->nextPendingConnection();

}

