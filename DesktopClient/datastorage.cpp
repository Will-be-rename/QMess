#include "datastorage.h"

DataStorage::DataStorage() :
    m_UserMtx(),
    m_MsgMtx(),
    m_Statuses(),
    m_Messages()
{

}

DataStorage &DataStorage::getInstance()
{
    static DataStorage instance;
    return instance;
}

void DataStorage::addUserStatus(const UserStatus newStatus)
{
    m_UserMtx.lock();
    m_Statuses.push(newStatus);
    m_UserMtx.unlock();
}

void DataStorage::addMessage(const Message newMessage)
{
    m_MsgMtx.lock();
    m_Messages.push(newMessage);
    m_MsgMtx.unlock();
}

UserStatus DataStorage::getUserStatus()
{
    m_UserMtx.lock();
    auto returnValue = m_Statuses.front();
    m_Statuses.pop();
    m_UserMtx.unlock();
    return returnValue;
}

Message DataStorage::getMessage()
{
    m_MsgMtx.lock();
    auto returnValue = m_Messages.front();
    m_Messages.pop();
    m_MsgMtx.unlock();
    return returnValue;
}

UserStatus &DataStorage::getCurrentUser()
{
    return m_CurrentUser;
}

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
