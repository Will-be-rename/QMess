#ifndef SESSIONCLIENT_H
#define SESSIONCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QVector>

#include "QRunable/runnabledirector.h"
#include "models.h"
class SessionClient : public QObject
{
    Q_OBJECT
public:
    explicit SessionClient(QObject *parent = nullptr);
    void SetSocket(qintptr handle);
    QTcpSocket* GetSocket();
    UserStatus getUserStatus();
signals:

public slots:
    void disconnected();
    void readyRead();
    void notifyEveryone(QByteArray data);
    void sendData(QTcpSocket* socket, QByteArray data);
private:
    void setUserStatus(UserStatus newUser);
    void setUpUser();

private:
    QTcpSocket* m_socket;
    UserStatus m_user;

};

#endif // SESSIONCLIENT_H
