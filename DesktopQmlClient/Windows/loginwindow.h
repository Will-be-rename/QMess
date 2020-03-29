#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QObject>
#include <Processors/eventmessageprocessor.h>

class LoginWindow : public QObject
{
    Q_OBJECT
public:
    LoginWindow(QObject * parent = nullptr);

private:
    EventMessageProcessor m_eventProcessor;
};

#endif // LOGINWINDOW_H
