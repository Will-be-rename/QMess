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
    QByteArray getUserStatusBytes();
    bool operator==(const SessionClient& other);
signals:
    void notifyEveryoneSignal(QByteArray data);
    void notifyUser(QByteArray data, size_t userId);
    void userReady(SessionClient*);
public slots:
    void disconnected();
    void readyRead();
    void notifyEveryone(QByteArray data);
    void sendData(QTcpSocket* socket, QByteArray data);
    void setUserStatus(UserStatus newUser);
    void setUserStatus(size_t      m_userId,
                      QString     m_userName,
                      bool        m_isOnline);
    void notifyUserSlot(QByteArray data, size_t userId);
private:
    void setUpUser();

private:
    QTcpSocket* m_socket;
    UserStatus m_user;

};

#endif // SESSIONCLIENT_H
