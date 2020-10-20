#pragma once

#include <QString>
#include <QDataStream>
#include <QVector>

typedef int UserId;
typedef long long MessageId;

struct Message
{
    MessageId       m_idMessage;
    UserId          m_idSender;
    UserId          m_idReceiver;
    QString         m_textBody;
    QString         m_dateTime;
    friend QDataStream &operator<<(QDataStream &ds, const Message &a);
    friend QDataStream &operator>>(QDataStream &ds, Message &a);
};

struct UserStatus // UserStatus ???
{
    UserId      m_userId;
    QString     m_userName;
    bool        m_isOnline;
    friend QDataStream &operator<<(QDataStream &ds, const UserStatus &a);
    friend QDataStream &operator>>(QDataStream &ds, UserStatus &a);
    bool operator<(const UserStatus& other) {return this->m_userId < other.m_userId;}
};
//to hashing use qcryptographichash
struct LoginPackage
{
    QByteArray m_login; // hash of string
    QByteArray m_password; // hash of password
    friend QDataStream &operator<<(QDataStream &ds, const LoginPackage &a);
    friend QDataStream &operator>>(QDataStream &ds, LoginPackage &a);
};

struct UserData
{
    UserId              m_userId;
    QString             m_userName;
    QVector<UserStatus> m_friends;
};

struct HistoryData
{
    UserId                 m_currentUserId;
    UserId                 m_friendUserId;
    QVector<Message>    m_historyData;
    friend QDataStream &operator<<(QDataStream &ds, const HistoryData &a);
    friend QDataStream &operator>>(QDataStream &ds, HistoryData &a);
};

struct HistoryDataRequest
{
    UserId                 m_currentUserId;
    UserId                 m_friendUserId;
    int                    m_size;
    friend QDataStream &operator<<(QDataStream &ds, const HistoryDataRequest &a);
    friend QDataStream &operator>>(QDataStream &ds, HistoryDataRequest &a);
};

struct FriendRequest
{
    UserId m_currentUser;
    UserId m_target;
};

enum PackageType
{
    eUserStatus,
    eMessage,
    eMessageHistoryRequest,
    eMessageHistoryResponse,
    eCurrentUserResponse,
    eCurrentUserRequest,
    eAddFriend,
    eRemoveFriend,
};
