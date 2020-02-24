#ifndef MESSAGEVIEW_H
#define MESSAGEVIEW_H
#include <QString>
#include <QDateTime>
class MessageView
{
public:
    MessageView(QString textBody, QDateTime dateTime, bool isReceived = 0);
    QString getTextBody() const;
    QString getDate()     const;
    QString getTime()     const;
    bool    isReceived()  const;
private:
    QString m_textBody;
    QDateTime m_dateTime;
    bool m_isReceived;
};

#endif // MESSAGEVIEW_H
