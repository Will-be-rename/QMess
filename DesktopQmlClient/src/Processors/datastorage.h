#ifndef DATASTORAGE_H
#define DATASTORAGE_H

#include <queue>
#include <mutex>

#include<QVector>
#include <QDataStream>

#include "modelsAPI.h"

class DataStorage : public QObject
{
    Q_OBJECT
public:
    static DataStorage&    getInstance  ();
    void            addUserStatus(const UserStatus newStatus);
    void            addMessage   (const Message newMessage);
    UserStatus      getUserStatus();
    Message         getMessage   ();
    UserStatus&     getCurrentUser();
    QVector<UserStatus> onlineUsers;
public slots:
    void            setCurrentUser(const UserStatus& currentUser);
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
