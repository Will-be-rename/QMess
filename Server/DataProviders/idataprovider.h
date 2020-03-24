#ifndef IDATAPROVIDER_H
#define IDATAPROVIDER_H

#include <QObject>

#include "models.h"
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

#endif // IDATAPROVIDER_H
