#ifndef MODELS_H
#define MODELS_H

#include <QString>
#include <QDataStream>
#include <QVector>

struct Message
{
    size_t          m_idMessage;
    size_t          m_idSender;
    size_t          m_idReceiver;
    QString         m_textBody;
    QString         m_dateTime;
    friend QDataStream &operator<<(QDataStream &ds, const Message &a);
    friend QDataStream &operator>>(QDataStream &ds, Message &a);
};

struct UserStatus // UserStatus ???
{
    size_t      m_userId;
    QString     m_userName;
    bool        m_isOnline;
    friend QDataStream &operator<<(QDataStream &ds, const UserStatus &a);
    friend QDataStream &operator>>(QDataStream &ds, UserStatus &a);
};
//to hashing use qcryptographichash
struct LoginPackage
{
    QByteArray m_login; // hash of string
    QByteArray m_password; // hash of password
};

struct UserData
{
    size_t              m_userId;
    QString             m_userName;
    QVector<UserStatus> m_friends;
};

struct HistoryData
{
    size_t              m_currentUserId;
    size_t              m_friendUserId;
    QVector<Message>    m_historyData;
};
enum PackageType
{
    eUserStatus,
    eMessage,
    eMessageHistoryRequest,
    eMessageHistoryResponse,
    eCurrentUserResponse,
    eCurrentUserRequest,
};

#endif //  MODELS_H
