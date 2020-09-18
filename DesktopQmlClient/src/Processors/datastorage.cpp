#include "datastorage.h"

#include <QDebug>

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

void DataStorage::setCurrentUser(const UserStatus &currentUser)
{
    qDebug() << "DataStorage::setCurrentUser id = " << currentUser.m_userId;
    m_CurrentUser = currentUser;
}
