#ifndef SERVERRUNNER_H
#define SERVERRUNNER_H

#include <QTcpServer>

class ServerRunner : public QTcpServer
{
    Q_OBJECT
public:
    ServerRunner();
    void StartServer();
public slots:
    void incomingConnection(qintptr handle) override;
private:
};

#endif // SERVERRUNNER_H
