#include "models.h"
QDataStream &operator<<(QDataStream &out, const Message &a)
{
    out << a.m_idMessage << a.m_idSender << a.m_idReceiver << a.m_textBody << a.m_dateTime;
    return out;
}

QDataStream &operator>>(QDataStream &in, Message &a)
{
    in >> a.m_idMessage >> a.m_idSender >> a.m_idReceiver >> a.m_textBody >> a.m_dateTime;
    return in;
}

QDataStream &operator<<(QDataStream &out, const UserStatus &a)
{
    out << a.m_isOnline << a.m_userId << a.m_userName ;
    return out;
}

QDataStream &operator>>(QDataStream &in, UserStatus &a)
{
    in >> a.m_isOnline >> a.m_userId >> a.m_userName ;
    return in;
}

QDataStream &operator<<(QDataStream &out, const HistoryData &a)
{
    out << a.m_currentUserId << a.m_friendUserId << a.m_historyData;
    return out;
}

QDataStream &operator>>(QDataStream &in, HistoryData &a)
{
    in >> a.m_currentUserId >> a.m_friendUserId >> a.m_historyData;
    return in;
}
