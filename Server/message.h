#ifndef MESSAGE_H
#define MESSAGE_H

#include <QString>
#include <QDataStream>

struct Message
{
    size_t          m_idMessage;
    size_t          m_idSender;
    size_t          m_idReceiver;
    QString         m_textBody;
    QString         m_dateTime;
    friend QDataStream &operator<<(QDataStream &ds, const Message &a);
    friend QDataStream &operator>>(QDataStream &ds, Message &a);
};

QDataStream& operator>>(QDataStream &ds, Message &a)
{
    ds >> a.m_idMessage >> a.m_idSender >> a.m_idReceiver >> a.m_textBody >> a.m_dateTime;
    return ds;

}
QDataStream& operator<<(QDataStream &ds, const Message &a)
{
    ds << a.m_idMessage << a.m_idSender << a.m_idReceiver << a.m_textBody << a.m_dateTime;
    return ds;
}

#endif // MESSAGE_H
