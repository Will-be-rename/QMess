#include "setupuserhandler.h"
#include "models.h"

SetUpUserHandler::SetUpUserHandler(QObject *parent) : QObject(parent)
{

}

void SetUpUserHandler::setSession(SessionClient* session)
{
    m_session = session;
}

void SetUpUserHandler::run()
{

}
