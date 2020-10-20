#pragma once

#include <QObject>
#include <optional>
#include <set>

#include "modelsAPI.h"
class IDataProvider : public QObject
{
    Q_OBJECT
public:
    explicit IDataProvider(QObject *parent = nullptr);
    virtual void        addToHistory(const Message& msg) = 0;
    virtual void        createMessageId(Message& msg) = 0;
    virtual std::optional<HistoryData> getHistory(int firstUserId, int secondUserId, int size) = 0;
    virtual std::optional<UserStatus>  getUserData(const LoginPackage& data) = 0;
    virtual const std::set<UserStatus>& getOnlineUsers() = 0;
    virtual void removeOnlineUser(const UserStatus& ) = 0;
    virtual void addOnlineUser(const UserStatus& ) = 0;
signals:

public slots:
};
