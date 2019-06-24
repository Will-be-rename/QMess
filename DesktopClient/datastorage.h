#ifndef DATASTORAGE_H
#define DATASTORAGE_H

#include <queue>
#include <mutex>

class UserStatus{};
class Message{};


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
};

#endif // DATASTORAGE_H
