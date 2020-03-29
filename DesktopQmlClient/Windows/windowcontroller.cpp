#include "windowcontroller.h"

WindowController::WindowController():m_engine(),
                                     m_chatWindow(),
                                     m_loginWindow()
{
    m_chatWindow.registerModels(&m_engine);
}

void WindowController::start()
{
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    m_engine.load(url);
}
