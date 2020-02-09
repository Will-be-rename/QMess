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
    bool operator==(const SessionClient& other);
signals:
    void notifyEveryoneSignal(QByteArray data);
    void notifyReciever(QByteArray data, size_t recieverId);
    void notifySender(QByteArray data, size_t senderId);
public slots:
    void disconnected();
    void readyRead();
    void notifyEveryone(QByteArray data);
    void sendData(QTcpSocket* socket, QByteArray data);
    void setUserStatus(UserStatus newUser);
    void setUserStatus(size_t      m_userId,
                      QString     m_userName,
                      bool        m_isOnline);
    void notifyRecieverSlot(QByteArray data, size_t recieverId);
    void notifySenderSlot(QByteArray data, size_t senderId);
private:
    void setUpUser();

private:
    QTcpSocket* m_socket;
    UserStatus m_user;

};

#endif // SESSIONCLIENT_H
