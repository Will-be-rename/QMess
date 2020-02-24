#ifndef EVENTMESSAGEPROCESSOR_H
#define EVENTMESSAGEPROCESSOR_H

#include <QObject>
#include <QTcpSocket>

#include "tcpdataprovider.h"
#include "datastorage.h"
//#include "cachedmessagehistory.h"
class EventMessageProcessor : public QObject
{
    Q_OBJECT
public:
    explicit EventMessageProcessor(QObject *parent = nullptr);
    void processEvents();// main method
    //CachedMessageHistory    m_cachedHistory;
    TcpDataProvider& dataProvider();

public slots:
    void sendMessage        (const Message& newMessage);
    void sendUserStatus     (const UserStatus& newStatus);

private slots:
    void notify();
private:
    QTcpSocket              m_socket;
    TcpDataProvider         m_dataProvider;

};

#endif // EVENTMESSAGEPROCESSOR_H
