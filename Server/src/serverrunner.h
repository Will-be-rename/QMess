#pragma once

#include <QTcpServer>
#include "sessionclient.h"

class ServerRunner : public QTcpServer
{
    Q_OBJECT
public:
    ServerRunner();
    void StartServer();
public slots:
    void incomingConnection(qintptr handle) override;
    void notifyEveryone(QByteArray bytes);
    void notify(QByteArray bytes, int clientId);
    void addConnection(SessionClient* connection);
private:
    QVector<SessionClient*> m_clients;
};
