#ifndef SETUPUSERHANDLER_H
#define SETUPUSERHANDLER_H

#include <QObject>
#include <QRunnable>
#include <QTcpSocket>

#include "sessionclient.h"
class SetUpUserHandler : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit SetUpUserHandler(QObject *parent = nullptr);
    void setSession(SessionClient* session);
protected:
    void run() override;

signals:
    void finish(QTcpSocket* socket, QByteArray data);

private:
    SessionClient* m_session;
};

#endif // SETUPUSERHANDLER_H
