#ifndef CONNECTIONHANDLER_H
#define CONNECTIONHANDLER_H

#include <QObject>
#include <QRunnable>
class ConnectionHandler : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit ConnectionHandler(QObject *parent = nullptr);
protected:
    void run() override;
signals:
    void finish(QByteArray data);
public slots:
};

#endif // CONNECTIONHANDLER_H
