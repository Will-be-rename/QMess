#ifndef SERVERRUNNER_H
#define SERVERRUNNER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QByteArray>

class ServerRunner : public QObject
{
    Q_OBJECT
public:
    ServerRunner();
public slots:
    void onNewConnection();
private:
    QTcpServer m_server;
};

#endif // SERVERRUNNER_H
