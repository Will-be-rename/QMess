#ifndef RUNABLEDIRECTOR_H
#define RUNABLEDIRECTOR_H

#include <QRunnable>
#include <QObject>
#include <QAbstractSocket>

class RunnableDirector : public QRunnable
{
public:
    RunnableDirector();
    void setSocket(QAbstractSocket* socket);
protected:
    void run() override;
private:
    QAbstractSocket* socket;
};

#endif // RUNABLEDIRECTOR_H
