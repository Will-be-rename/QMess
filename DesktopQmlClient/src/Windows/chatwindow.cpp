#include "chatwindow.h"

ChatWindow::ChatWindow(QObject *parent):
    QObject(parent),
    m_EventProcessor()
{
     m_EventProcessor.processEvents();
     connect(&m_EventProcessor, SIGNAL(newUserDetected(User)),
                      this, SLOT(userStatusChangedSlot(User)));
     connect(&m_EventProcessor, SIGNAL(newMessageReceived(MessageView)),
                      this, SLOT(newMessageReceivedSlot(MessageView)));
     connect(&m_messagesModel, SIGNAL(messageIsSent(QString)),
                      this, SLOT(sendMessageSlot(QString)));
     connect(&m_userModel, SIGNAL(userSelected()),
                      this, SLOT(userSelectedSlot()));
}

void ChatWindow::registerModels(QQmlApplicationEngine* engine)
{
    engine->rootContext()->setContextProperty(QStringLiteral("messagesModel"), &m_messagesModel);
    engine->rootContext()->setContextProperty(QStringLiteral("userModel"), &m_userModel);
}

void ChatWindow::userStatusChangedSlot (const User& newUser)
{
    qDebug()<<"Your id: "<< DataStorage::getInstance().getCurrentUser().m_userId << " Received id: " << newUser.getUserId();
    m_userModel.addUser(newUser);
}

void ChatWindow::newMessageReceivedSlot(const MessageView& message)
{
    m_messagesModel.addMessage(message);
}

void ChatWindow::sendMessageSlot(const QString& messageBody)
{
    if(false == m_userModel.isEmpty())
    {
        MessageView newMessage;
        newMessage.setTextBody(messageBody);
        newMessage.setChatId(m_userModel.getCurrentUser().getUserId());
        m_EventProcessor.sendMessage(newMessage);
    }
}

void ChatWindow::userSelectedSlot()
{
    int friendId = m_userModel.getCurrentUser().getUserId();
    m_EventProcessor.sendHistoryRequest(friendId);

}
