#include "windowcontroller.h"

WindowController::WindowController()
{
    m_loginWindow = new LoginWindow();
    m_chatWindow = new ChatWindow();
}

WindowController::~WindowController()
{
    delete m_loginWindow;
    delete m_chatWindow;
}

void WindowController::start()
{
    m_chatWindow->show();
}

