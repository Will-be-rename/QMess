#ifndef IDATAPROVIDER_H
#define IDATAPROVIDER_H

#include <QObject>

#include "models.h"
class IDataProvider : public QObject
{
    Q_OBJECT
public:
    explicit IDataProvider(QObject *parent = nullptr);
    virtual void        addToHistory(Message msg) = 0;
    virtual HistoryData getHistory(int firstUserId, int secondUserId, int size) = 0;
    virtual UserData    getUserData(LoginPackage data) = 0;
signals:

public slots:
};

#endif // IDATAPROVIDER_H
