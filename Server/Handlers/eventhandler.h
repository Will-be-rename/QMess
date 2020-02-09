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
    void notifyReciever(QByteArray data, size_t recieverId);
    void notifySender(QByteArray data, size_t senderId);
public slots:

};

#endif // EVENTHANDLER_H
