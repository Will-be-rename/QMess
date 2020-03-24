#ifndef MOCKDATAPROVIDER_H
#define MOCKDATAPROVIDER_H

#include "idataprovider.h"

class MockDataProvider : public IDataProvider
{
public:
    MockDataProvider();
    virtual void        addToHistory(const Message& msg);
    virtual void        createMessageId(Message& msg);
    virtual HistoryData getHistory(int firstUserId, int secondUserId, int size);
    virtual UserStatus    getUserData(const LoginPackage& data);
signals:

public slots:
};

#endif // MOCKDATAPROVIDER_H
