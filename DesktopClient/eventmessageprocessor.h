#ifndef EVENTMESSAGEPROCESSOR_H
#define EVENTMESSAGEPROCESSOR_H

#include <QObject>
#include <QTcpSocket>
#include "datastorage.h"

class EventMessageProcessor : public QObject
{
    Q_OBJECT
public:
    explicit EventMessageProcessor(QObject *parent = nullptr);
    void processEvents();// main method
    void finish();
signals:

    void userStatusChanged  ();
    void newMessageRecieved ();
public slots:
    void sendMessage        (const Message& newMessage);
    void sendUserStatus     (const UserStatus& newStatus);

private slots:
    void notify();
private:
    volatile bool   m_isRunning;
    QTcpSocket      m_socket;
};

#endif // EVENTMESSAGEPROCESSOR_H
