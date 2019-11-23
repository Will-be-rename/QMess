#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QObject>
#include <QTcpSocket>

#include "models.h"

class EventHandler : public QObject
{
    Q_OBJECT
public:
    explicit EventHandler(QObject *parent = nullptr);
    void handleHistoryRequest();
    void handleMessage(Message data);
    void handleUserStatus(UserStatus data);
signals:
    void finished(QTcpSocket* socket, QByteArray data);
public slots:

};

#endif // EVENTHANDLER_H
