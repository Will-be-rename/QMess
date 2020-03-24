#include "user.h"
#include <QRandomGenerator>

User::User(const int& userId, const QString& name, const bool& online):
           m_userId(userId),
           m_name(name),
           m_online(online)
{
    m_incommingMessages = QRandomGenerator::global()->generate() % 3;
}

int User::getUserId() const
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
int User::getIncommningMessages() const
{

    return m_incommingMessages;
}

void User::setOnline(const bool& isOnline)
{
    m_online = isOnline;
}
