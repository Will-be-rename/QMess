#ifndef RUNABLEDIRECTOR_H
#define RUNABLEDIRECTOR_H

#include <QRunnable>
#include <QObject>
#include <QTcpSocket>

class RunnableDirector : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit RunnableDirector(QObject *parent = nullptr);
    void setSocket(QAbstractSocket* socket);
protected:
    void run() override;
signals:
    void notifyReciever(QByteArray data, int recieverId);
    void notifySender(QByteArray data, int senderId);
    void currentUserRequest();
private slots:
    void notifyRecieverProvider(QByteArray data, int recieverId);
    void notifySenderProvider(QByteArray data, int senderId);
private:
    QAbstractSocket* socket;
};

#endif // RUNABLEDIRECTOR_H
