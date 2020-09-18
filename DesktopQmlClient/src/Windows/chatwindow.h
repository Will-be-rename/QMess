#ifndef CHATWINDOW_H
#define CHATWINDOW_H
#include "ViewModels/messagesmodel.h"
#include "ViewModels/usermodel.h"
#include "Processors/eventmessageprocessor.h"

#include <QQmlApplicationEngine>
#include <QQmlContext>

class ChatWindow : public QObject
{
    Q_OBJECT
public:
    ChatWindow(QObject *parent = nullptr);
    void registerModels(QQmlApplicationEngine* engine);
private:
    EventMessageProcessor m_EventProcessor;
    MessagesModel         m_messagesModel;
    UserModel             m_userModel;
private slots:
    void userStatusChangedSlot  (const User& user);
    void newMessageReceivedSlot (const MessageView& message);
    void sendMessageSlot        (const QString& messageBody);
    void userSelectedSlot();
signals:
    void sendMessage(const Message& message);
};

#endif // CHATWINDOW_H
