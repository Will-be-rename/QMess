#ifndef MODELS_H
#define MODELS_H

#include <string>

struct Message
{
    size_t          m_idMessage;
    size_t          m_idSender;
    size_t          m_idReceiver;
    std::string     m_textBody;
    std::string     m_dateTime;
};

struct UserInfo // UserStatus ???
{
    size_t      m_userId;
    std::string m_userName;
    bool        m_isOnline;
};

enum PackageType
{
    eUserStatus,
    eMessage,
};
#endif //  MODELS_H
