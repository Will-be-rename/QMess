#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QObject>
#include <QTcpSocket>

#include "models.h"

class EventHandler : public QObject
{
    Q_OBJECT
public:
    explicit EventHandler(QTcpSocket* socket, QObject *parent = nullptr);
    void handleHistoryRequest();
    void handleMessage(Message data);
    void handleUserStatus(UserStatus data);
signals:

public slots:

private:
    QTcpSocket* m_socket;

};

#endif // EVENTHANDLER_H
