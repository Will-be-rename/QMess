#include "user.h"

User::User(const size_t& userId, const QString& name, const bool& online):
           m_userId(userId),
           m_name(name),
           m_online(online)
{
}

size_t User::getUserId() const
{
    return m_userId;
}
QString User::getUserName() const
{
    return m_name;
}
bool User::isOnline() const
{
    return m_online;
}
