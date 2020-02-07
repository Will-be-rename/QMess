#ifndef WINDOWCONTROLLER_H
#define WINDOWCONTROLLER_H
#include "chatwindow.h"
#include "loginwindow.h"

class WindowController : public QObject
{
    Q_OBJECT

public:
    WindowController();
    ~WindowController();
    void start();

private:
    LoginWindow* m_loginWindow;
    ChatWindow*  m_chatWindow;
};

#endif // WINDOWCONTROLLER_H
