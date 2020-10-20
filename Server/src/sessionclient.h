#pragma once

#include <QObject>
#include <QTcpSocket>
#include <QVector>

#include "QRunable/runnabledirector.h"
#include "Commands/IWorker.h"
#include "DataProviders/idataprovider.h"
#include "modelsAPI.h"
class SessionClient : public QObject
{
    Q_OBJECT
public:
    SessionClient(commands::IWorker& worker, IDataProvider& datatprovider, QObject *parent = nullptr);
    void SetSocket(qintptr handle);
    QTcpSocket* GetSocket();
    UserStatus getUserStatus();
    QByteArray getUserStatusBytes();
    bool operator==(const SessionClient& other);
signals:
    void notifyEveryoneSignal(QByteArray data);
    void notifyUser(QByteArray data, int userId);
    void userReady(SessionClient*);
public slots:
    void disconnected();
    void readyRead();
    void notifyEveryone(QByteArray data);
    void sendData(QTcpSocket* socket, QByteArray data);
    void setUserStatus(UserStatus newUser);
    void setUserStatus(int      m_userId,
                      QString     m_userName,
                      bool        m_isOnline);
    void notifyUserSlot(QByteArray data, int userId);

private:
    QTcpSocket* m_socket;
    UserStatus m_user;
    commands::IWorker& m_worker;
    IDataProvider& m_dataprovider;

};
