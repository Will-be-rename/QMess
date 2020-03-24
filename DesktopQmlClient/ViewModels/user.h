#ifndef USER_H
#define USER_H

#include <QString>

class User
{
public:
    User() = default;
    User(const int& userId, const QString& name, const bool& online);
    int  getUserId() const;
    QString getUserName() const;
    bool    isOnline() const;
    int     getIncommningMessages() const;
    void    setOnline(const bool& isOnline);
private:
    int  m_userId;
    QString m_name;
    bool    m_online;
    int m_incommingMessages;
};

#endif // USER_H
