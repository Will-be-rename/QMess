#pragma once

#include <QObject>
#include <QRunnable>

#include "modelsAPI.h"

class ConnectionHandler : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit ConnectionHandler(QObject *parent = nullptr);
protected:
    void run() override;
signals:
    void finish(QByteArray data);
    void userFound
    (int      m_userId,
    QString     m_userName,
    bool        m_isOnline);
public slots:
};
