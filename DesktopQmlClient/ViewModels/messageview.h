#ifndef MESSAGEVIEW_H
#define MESSAGEVIEW_H
#include <QString>
#include <QDateTime>
class MessageView
{
public:
    MessageView() = default;
    MessageView(QString textBody, QString dateTime, int chatId);
    QString getTextBody() const;
    QString getDateTime() const;
    int     getChatId()   const;
    void    setTextBody(const QString& textBody);
    void    setChatId(const int& chatId);
private:
    QString m_textBody;
    QString m_dateTime;
    int     m_chatId;
};

#endif // MESSAGEVIEW_H
