#ifndef EVENTMESSAGEPROCESSOR_H
#define EVENTMESSAGEPROCESSOR_H

#include <QObject>
#include <QTcpSocket>
#include "datastorage.h"
#include "cachedmessagehistory.h"
class EventMessageProcessor : public QObject
{
    Q_OBJECT
public:
    explicit EventMessageProcessor(QObject *parent = nullptr);
    void processEvents();// main method
    CachedMessageHistory    m_cachedHistory;
signals:

    void userStatusChanged  ();
    void newMessageRecieved ();
    void chatHistoryUpdated (size_t);
public slots:
    void sendMessage        (const Message& newMessage);
    void sendUserStatus     (const UserStatus& newStatus);

private slots:
    void notify();
private:
    QTcpSocket              m_socket;

};

#endif // EVENTMESSAGEPROCESSOR_H
