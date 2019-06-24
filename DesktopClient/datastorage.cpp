#include "datastorage.h"

DataStorage::DataStorage()
{

}

DataStorage &DataStorage::getInstance()
{
    static DataStorage instance;
    return instance;
}

void DataStorage::addUserStatus(const UserStatus newStatus)
{
    m_Statuses.push(newStatus);
}

void DataStorage::addMessage(const Message newMessage)
{
    m_Messages.push(newMessage);
}

UserStatus DataStorage::getUserStatus()
{
    auto returnValue = m_Statuses.front();
    m_Statuses.pop();
    return returnValue;
}

Message DataStorage::getMessage()
{
    auto returnValue = m_Messages.front();
    m_Messages.pop();
    return returnValue;
}
