#ifndef EVENTMESSAGEPROCESSOR_H
#define EVENTMESSAGEPROCESSOR_H

#include <QObject>
#include <QTcpSocket>

#include "tcpdataprovider.h"
#include "datastorage.h"
#include "ViewModels/user.h"
#include "ViewModels/messageview.h"

//#include "cachedmessagehistory.h"
class EventMessageProcessor : public QObject
{
    Q_OBJECT
public:
    explicit EventMessageProcessor(QObject *parent = nullptr);
    void processEvents();// main method
    //CachedMessageHistory    m_cachedHistory;
    TcpDataProvider& dataProvider();
    void sendMessage (const MessageView& newMessage);
    void sendHistoryRequest(int friendId);

public slots:
    void sendUserStatus     (const UserStatus& newStatus);

private slots:
    void notify();
    void clientConnected();
    void newUserStatusDetectedSlot(const UserStatus& newStatus);
    void newMessageDetectedSlot(const Message& newMessage);

signals:
    void newUserDetected(const User& newUser);
    void newMessageReceived(const MessageView& newMessage);
    void sendHistoryDataRequest(const HistoryDataRequest& historyDataRequest);
private:
    QTcpSocket              m_socket;
    TcpDataProvider         m_dataProvider;

};

#endif // EVENTMESSAGEPROCESSOR_H
