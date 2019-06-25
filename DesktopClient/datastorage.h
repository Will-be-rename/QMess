#ifndef DATASTORAGE_H
#define DATASTORAGE_H

#include <queue>
#include <mutex>

#include <QDataStream>

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

enum PackageType
{
    eUserStatus,
    eMessage,
};




class DataStorage
{
public:
    static DataStorage&    getInstance  ();
    void            addUserStatus(const UserStatus newStatus);
    void            addMessage   (const Message newMessage);
    UserStatus      getUserStatus();
    Message         getMessage   ();
    UserStatus&     getCurrentUser();
private:
    DataStorage();
    DataStorage(const DataStorage&) = delete;
    DataStorage(DataStorage&&) = delete;
    DataStorage& operator =(const DataStorage&) = delete;
    DataStorage& operator =(DataStorage&&) = delete;

    // 2 threads need be sync
    std::mutex                  m_UserMtx;
    std::mutex                  m_MsgMtx;
    std::queue<UserStatus>      m_Statuses;
    std::queue<Message>         m_Messages;
    UserStatus                  m_CurrentUser;
};

#endif // DATASTORAGE_H
