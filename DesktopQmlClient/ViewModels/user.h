#ifndef USER_H
#define USER_H

#include <QString>

class User
{
public:
    User() = default;
    User(const size_t& userId, const QString& name, const bool& online);
    size_t  getUserId() const;
    QString getUserName() const;
    bool    isOnline() const;
    int getIncommningMessages() const;
private:
    size_t  m_userId;
    QString m_name;
    bool    m_online;
    int m_incommingMessages;
};

#endif // USER_H
