#include "chatwindow.h"

ChatWindow::ChatWindow():m_EventProcessor()
{
     m_EventProcessor.processEvents();
     m_messagesModel.addMessage({"Hello",QDateTime()});
     m_messagesModel.addMessage({"Hello",QDateTime()});
     m_messagesModel.addMessage({"Lorem Ipsum - это текст-\"рыба\", часто используемый в печати и вэб-дизайне. Lorem Ipsum является стандартной \"рыбой\" для текстов на латинице с начала XVI века. В то время некий безымянный печатник создал большую коллекцию размеров и форм шрифтов, используя Lorem Ipsum для распечатки образцов.",QDateTime()});
     m_messagesModel.addMessage({"Lorem Ipsum - это текст-\"рыба\", часто используемый в печати и вэб-дизайне. Lorem Ipsum является стандартной \"рыбой\" для текстов на латинице с начала XVI века. В то время некий безымянный печатник создал большую коллекцию размеров и форм шрифтов, используя Lorem Ipsum для распечатки образцов.",QDateTime()});

}

void ChatWindow::registerModels(QQmlApplicationEngine* engine)
{
    engine->rootContext()->setContextProperty(QStringLiteral("messagesModel"), &m_messagesModel);
    engine->rootContext()->setContextProperty(QStringLiteral("userModel"), &m_userModel);
}
