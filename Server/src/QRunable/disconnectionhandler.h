#pragma once

#include <QRunnable>
#include <QObject>

#include "modelsAPI.h"
class DisconnectionHandler : public QObject, public QRunnable
{
    Q_OBJECT
public:
    DisconnectionHandler(QObject* parent = nullptr);
    void setUser(UserStatus user);
protected:
    void run() override;
signals:
    void finish(QByteArray data);
private:
    UserStatus m_user;
};
