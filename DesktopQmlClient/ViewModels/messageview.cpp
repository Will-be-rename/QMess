#include "messageview.h"

MessageView::MessageView(QString textBody, QDateTime dateTime, bool isReceived):
                         m_textBody(textBody),
                         m_dateTime(dateTime),
                         m_isReceived(isReceived)
{

}

QString MessageView::getTextBody() const
{
    return m_textBody;
}

QString MessageView::getDate() const
{
    return m_dateTime.date().toString(Qt::DateFormat::TextDate);
}
QString MessageView::getTime() const
{
    return m_dateTime.time().toString(Qt::DateFormat::TextDate);
}

bool MessageView::isReceived() const
{
    return m_isReceived;
}

