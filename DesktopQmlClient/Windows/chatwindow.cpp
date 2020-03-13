#include "chatwindow.h"

ChatWindow::ChatWindow(QObject *parent):
    QObject(parent),
    m_EventProcessor()
{
     m_EventProcessor.processEvents();
     m_messagesModel.addMessage({"Hello",QDateTime()});
     m_messagesModel.addMessage({"Hello",QDateTime()});
     m_messagesModel.addMessage({"Lorem Ipsum - это текст-\"рыба\", часто используемый в печати и вэб-дизайне. Lorem Ipsum является стандартной \"рыбой\" для текстов на латинице с начала XVI века. В то время некий безымянный печатник создал большую коллекцию размеров и форм шрифтов, используя Lorem Ipsum для распечатки образцов.",QDateTime()});
     m_messagesModel.addMessage({"Lorem Ipsum - это текст-\"рыба\", часто используемый в печати и вэб-дизайне. Lorem Ipsum является стандартной \"рыбой\" для текстов на латинице с начала XVI века. В то время некий безымянный печатник создал большую коллекцию размеров и форм шрифтов, используя Lorem Ipsum для распечатки образцов.",QDateTime()});
     TcpDataProvider& dataProvider = m_EventProcessor.dataProvider();
     connect(&dataProvider, SIGNAL(newUserStatusDetected(UserStatus)),
                      this, SLOT(userStatusChangedSlot(UserStatus)));
}

void ChatWindow::registerModels(QQmlApplicationEngine* engine)
{
    engine->rootContext()->setContextProperty(QStringLiteral("messagesModel"), &m_messagesModel);
    engine->rootContext()->setContextProperty(QStringLiteral("userModel"), &m_userModel);
}

void ChatWindow::userStatusChangedSlot (const UserStatus& status)
{
    if(status.m_userId != DataStorage::getInstance().getCurrentUser().m_userId)
    {
        User newUser(status.m_userId,status.m_userName,status.m_isOnline);
        m_userModel.addUser(newUser);
    }
}
