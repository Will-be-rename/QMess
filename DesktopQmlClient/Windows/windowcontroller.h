#ifndef WINDOWCONTROLLER_H
#define WINDOWCONTROLLER_H

#include "Windows/chatwindow.h"

class WindowController
{
public:
    WindowController();
    void start();
private:
    QQmlApplicationEngine m_engine;
    ChatWindow            m_chatWindow;
};

#endif // WINDOWCONTROLLER_H
