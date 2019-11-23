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
    QTcpSocket* GetSocket();
signals:

public slots:
    void disconnected();
    void readyRead();
    void notifyEveryone(QByteArray data);

private:
    void getUserId();

private:
    QTcpSocket* m_socket;
    int m_userId;

};

#endif // SESSIONCLIENT_H
