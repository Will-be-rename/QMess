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
    void notifyReciever(QByteArray data, size_t recieverId);
    void notifySender(QByteArray data, size_t senderId);
    void finished(QTcpSocket* socket, QByteArray data);
private slots:
    void notifyRecieverProvider(QByteArray data, size_t recieverId);
    void notifySenderProvider(QByteArray data, size_t senderId);
    void forward(QTcpSocket* socket, QByteArray data);
private:
    QAbstractSocket* socket;
};

#endif // RUNABLEDIRECTOR_H
