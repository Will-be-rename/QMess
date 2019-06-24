#ifndef EVENTMESSAGEPROCESSOR_H
#define EVENTMESSAGEPROCESSOR_H

#include <QObject>

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
    void login              (const UserStatus& newStatus);
    void logout             (const UserStatus& newStatus);

private:
    void notify();
private:
    PackageType m_CurrentMessage;
    volatile bool m_isRunning;
};

#endif // EVENTMESSAGEPROCESSOR_H
