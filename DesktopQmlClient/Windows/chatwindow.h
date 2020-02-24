#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include "Processors/eventmessageprocessor.h"

class ChatWindow
{
public:
    ChatWindow();
private:
    EventMessageProcessor m_EventProcessor;
};

#endif // CHATWINDOW_H
