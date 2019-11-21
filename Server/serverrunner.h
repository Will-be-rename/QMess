#ifndef SERVERRUNNER_H
#define SERVERRUNNER_H

#include <QTcpServer>

class ServerRunner : public QTcpServer
{
    Q_OBJECT
public:
    ServerRunner();
public slots:
    void onNewConnection();
private:
};

#endif // SERVERRUNNER_H
