#include "eventhandler.h"

EventHandler::EventHandler(QTcpSocket* socket, QObject *parent) : QObject(parent), m_socket(socket)
{

}

void EventHandler::handleHistoryRequest()
{

}

void EventHandler::handleMessage(Message data)
{

}

void EventHandler::handleUserStatus(UserStatus data)
{

}
