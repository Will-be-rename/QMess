#ifndef WINDOWCONTROLLER_H
#define WINDOWCONTROLLER_H

#include "Windows/chatwindow.h"
#include "Windows/loginwindow.h"

class WindowController
{
public:
    WindowController();
    void start();
private:
    QQmlApplicationEngine m_engine;
    ChatWindow            m_chatWindow;
    LoginWindow           m_loginWindow;
};

#endif // WINDOWCONTROLLER_H
