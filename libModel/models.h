#ifndef MODELS_H
#define MODELS_H

#include <string>

struct Message
{
    size_t          m_idSender;
    size_t          m_idReceiver;
    std::string     m_textBody;
};

struct UserInfo // UserStatus ???
{
    size_t  m_userId;
    bool    m_isOnline;
};

enum PackageType
{
    eUserStatus,
    eMessage,
};
#endif //  MODELS_H
