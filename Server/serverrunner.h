#ifndef SERVERRUNNER_H
#define SERVERRUNNER_H

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
    void notify(QByteArray bytes, size_t clientId);
private:
    QVector<SessionClient*> m_clients;
};

#endif // SERVERRUNNER_H
