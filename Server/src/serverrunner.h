#pragma once

#include <QTcpServer>
#include "Commands/IWorker.h"
#include "DataProviders/idataprovider.h"
#include "sessionclient.h"

class ServerRunner : public QTcpServer
{
    Q_OBJECT
public:
    ServerRunner(commands::IWorker& worker, IDataProvider& datatprovider);
    void StartServer();
public slots:
    void incomingConnection(qintptr handle) override;
    void notifyEveryone(QByteArray bytes);
    void notify(QByteArray bytes, int clientId);
    void addConnection(SessionClient* connection);
private:
    QVector<SessionClient*> m_clients;
    commands::IWorker& m_worker;
    IDataProvider& m_dataprovider;
};
