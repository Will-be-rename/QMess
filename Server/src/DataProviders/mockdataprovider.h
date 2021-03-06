#pragma once

#include "idataprovider.h"

#include <vector>

class MockDataProvider : public IDataProvider
{
public:
    MockDataProvider();
    virtual void            addToHistory(const Message& msg);
    virtual void            createMessageId(Message& msg);
    virtual std::optional<HistoryData>     getHistory(int firstUserId, int secondUserId, int size);
    virtual std::optional<UserStatus>      getUserData(const LoginPackage& data);
    virtual const std::set<UserStatus>& getOnlineUsers();
    virtual void removeOnlineUser(const UserStatus& ) {}
    virtual void addOnlineUser(const UserStatus& ) {}
signals:

public slots:
private:
    std::vector<HistoryData> histories;
};
