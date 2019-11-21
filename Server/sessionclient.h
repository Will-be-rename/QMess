#ifndef SESSIONCLIENT_H
#define SESSIONCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QVector>

#include "QRunable/runnabledirector.h"
class SessionClient : public QObject
{
    Q_OBJECT
public:
    explicit SessionClient(QObject *parent = nullptr);
    void SetSocket(qintptr handle);
signals:

public slots:
    void connected();
    void disconnected();
    void readyRead();
    void result(int Number);

private:
    QTcpSocket* m_socket;

};
static QVector<SessionClient*> clients;
#endif // SESSIONCLIENT_H
