#ifndef CHATWINDOW_H
#define CHATWINDOW_H
#include "ViewModels/messagesmodel.h"
#include "ViewModels/usermodel.h"
#include "Processors/eventmessageprocessor.h"

#include <QQmlApplicationEngine>
#include <QQmlContext>

class ChatWindow
{
public:
    ChatWindow();
    void registerModels(QQmlApplicationEngine* engine);
private:
    EventMessageProcessor m_EventProcessor;
    MessagesModel         m_messagesModel;
    UserModel             m_userModel;

};

#endif // CHATWINDOW_H
