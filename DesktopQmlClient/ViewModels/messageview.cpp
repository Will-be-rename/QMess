#include "messageview.h"

MessageView::MessageView(QString textBody, QString dateTime, int chatId):
                         m_textBody(textBody),
                         m_dateTime(dateTime),
                         m_chatId(chatId)
{

}

QString MessageView::getTextBody() const
{
    return m_textBody;
}

QString MessageView::getDateTime() const
{
    return m_dateTime;
}

int MessageView::getChatId() const
{
    return m_chatId;
}

void MessageView::setTextBody(const QString& textBody)
{
    m_textBody = textBody;
}
void MessageView::setChatId(const int& chatId)
{
    m_chatId = chatId;
}
