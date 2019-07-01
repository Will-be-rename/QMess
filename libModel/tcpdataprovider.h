#ifndef TCPDATAPROVIDER_H
#define TCPDATAPROVIDER_H

#include <QTcpSocket>
#include <QObject>
#include "models.h"

class TcpDataProvider : public QObject
{
    Q_OBJECT
public:
    void sendMessage(QTcpSocket& socket, const Message& message);
    void sendUserStatus(QTcpSocket& socket, const UserStatus& message);
    void sendLoginPackage(QTcpSocket& socket, const UserStatus& message);
    void getData(QTcpSocket& socket);
signals :
    void newMessageDetected(const Message& message);
    void newUserStatusDetected(const UserStatus& message);
    void currentUserDetected(const UserStatus& userStatus);
};

#endif // TCPDATAPROVIDER_H
