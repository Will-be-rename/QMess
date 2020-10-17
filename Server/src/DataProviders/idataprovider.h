#pragma once

#include <QObject>

#include "modelsAPI.h"
class IDataProvider : public QObject
{
    Q_OBJECT
public:
    explicit IDataProvider(QObject *parent = nullptr);
    virtual void        addToHistory(const Message& msg) = 0;
    virtual void        createMessageId(Message& msg) = 0;
    virtual HistoryData getHistory(int firstUserId, int secondUserId, int size) = 0;
    virtual UserStatus    getUserData(const LoginPackage& data) = 0;
signals:

public slots:
};
