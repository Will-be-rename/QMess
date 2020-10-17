#pragma once

#include <QString>
#include <QDataStream>
#include <QVector>

struct Message
{
    int          m_idMessage;
    int          m_idSender;
    int          m_idReceiver;
    QString         m_textBody;
    QString         m_dateTime;
    friend QDataStream &operator<<(QDataStream &ds, const Message &a);
    friend QDataStream &operator>>(QDataStream &ds, Message &a);
};

struct UserStatus // UserStatus ???
{
    int      m_userId;
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
    friend QDataStream &operator<<(QDataStream &ds, const LoginPackage &a);
    friend QDataStream &operator>>(QDataStream &ds, LoginPackage &a);
};

struct UserData
{
    int              m_userId;
    QString             m_userName;
    QVector<UserStatus> m_friends;
};

struct HistoryData
{
    int                 m_currentUserId;
    int                 m_friendUserId;
    QVector<Message>    m_historyData;
    friend QDataStream &operator<<(QDataStream &ds, const HistoryData &a);
    friend QDataStream &operator>>(QDataStream &ds, HistoryData &a);
};

struct HistoryDataRequest
{
    int                 m_currentUserId;
    int                 m_friendUserId;
    int                 m_size;
    friend QDataStream &operator<<(QDataStream &ds, const HistoryDataRequest &a);
    friend QDataStream &operator>>(QDataStream &ds, HistoryDataRequest &a);
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
