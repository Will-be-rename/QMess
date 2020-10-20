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
    out << a.m_currentUserId << a.m_friendUserId << a.m_historyData.size();
    for(int i = 0; i < a.m_historyData.size(); i++)
    {
       out << a.m_historyData[i];
    }
    return out;
}

QDataStream &operator>>(QDataStream &in, HistoryData &a)
{
    int size = 0;
    in >> a.m_currentUserId >> a.m_friendUserId >> size;
    for(int i = 0; i < size; i++)
    {
        Message msg;
        in >> msg;
        a.m_historyData.push_back(msg);
    }
    return in;
}

QDataStream &operator<<(QDataStream &out, const LoginPackage &a)
{
    out << a.m_login << a.m_password;
    return out;
}
QDataStream &operator>>(QDataStream &in, LoginPackage &a)
{
    in >> a.m_login >> a.m_password;
    return in;
}

QDataStream &operator<<(QDataStream &out, const HistoryDataRequest &a)
{
    out << a.m_currentUserId << a.m_friendUserId << a.m_size;
    return out;
}

QDataStream &operator>>(QDataStream &in, HistoryDataRequest &a)
{
    in >> a.m_currentUserId >> a.m_friendUserId >> a.m_size;
    return in;
}
