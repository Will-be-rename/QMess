#include "mockdataprovider.h"
#include <QDebug>
MockDataProvider::MockDataProvider()
{

}

void MockDataProvider::addToHistory(const Message &msg)
{
    qDebug() << "MockDataProvider::addToHistory \n";
}

void MockDataProvider::createMessageId(Message &msg)
{
    qDebug() << "MockDataProvider::createMessageId \n";
    static int msgId = 0;
    msgId++;
    msg.m_idMessage = msgId;
}

HistoryData MockDataProvider::getHistory(int firstUserId, int secondUserId, int size)
{
   qDebug() << "MockDataProvider::getHistory \n";
}

UserStatus MockDataProvider::getUserData(const LoginPackage &loginData)
{
   qDebug() << "MockDataProvider::getUserData \n";
   static int newUserId = 0;
   newUserId++;
   UserStatus newUser {
       static_cast<int>(newUserId),
       "User "+ QString::number(newUserId),
       true};
   return newUser;
}
