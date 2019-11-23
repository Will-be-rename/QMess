#ifndef DISCONNECTIONHANDLER_H
#define DISCONNECTIONHANDLER_H

#include <QRunnable>
#include <QObject>

class DisconnectionHandler : public QObject, public QRunnable
{
    Q_OBJECT
public:
    DisconnectionHandler(QObject* parent = nullptr);
protected:
    void run() override;
signals:
    void finish(QByteArray data);
};

#endif // DISCONNECTIONHANDLER_H
