#ifndef DATASTORAGE_H
#define DATASTORAGE_H

#include <queue>

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


    std::queue<UserStatus>      m_Statuses;
    std::queue<Message>         m_Messages;
};

#endif // DATASTORAGE_H
