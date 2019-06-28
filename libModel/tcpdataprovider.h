#ifndef TCPDATAPROVIDER_H
#define TCPDATAPROVIDER_H

#include <QTcpSocket>

#include "models.h"

class TcpDataProvider : QObject
{
    Q_OBJECT
public:
    TcpDataProvider();
    void sendMessage(QTcpSocket& socket, const Message& message);
    void sendUserStatus(QTcpSocket& socket, const UserStatus& message);
    void sendLoginPackage(QTcpSocket& socket, const UserStatus& message);
    void getData(QTcpSocket& socket);
signals :
    void newMessageDetected(const Message& message);
    void newUserStatusDetected(const Message& message);
};

#endif // TCPDATAPROVIDER_H
