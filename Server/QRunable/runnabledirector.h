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
    void finish(QTcpSocket* socket, QByteArray data);
private:
    QAbstractSocket* socket;
};

#endif // RUNABLEDIRECTOR_H
