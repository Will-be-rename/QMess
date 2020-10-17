#pragma once

#include <QRunnable>
#include <QObject>
#include <QTcpSocket>

class RunnableDirector : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit RunnableDirector(QAbstractSocket *_socket, QObject *parent = nullptr);
protected:
    void run() override;
signals:
    void notifyReciever(QByteArray data, int recieverId);
    void notifySender(QByteArray data, int senderId);
    void currentUserRequest(int,QString,bool);
    void notifyEveryone(QByteArray data);
    void notify(QByteArray data, int userId);
private slots:
    void notifyRecieverProvider(QByteArray data, int recieverId);
    void notifySenderProvider(QByteArray data, int senderId);
private:
    QAbstractSocket* socket;
};
