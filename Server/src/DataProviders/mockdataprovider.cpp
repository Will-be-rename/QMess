#include "mockdataprovider.h"
#include <QDebug>
MockDataProvider::MockDataProvider()
{

}

void MockDataProvider::addToHistory(const Message &msg)
{
    qDebug() << "MockDataProvider::addToHistory \n";
    auto iter = histories.end();
    for(iter = histories.begin();iter != histories.end(); iter++)
    {
        if((iter->m_currentUserId == msg.m_idSender && iter->m_friendUserId == msg.m_idReceiver) ||
                (iter->m_currentUserId == msg.m_idReceiver && iter->m_friendUserId == msg.m_idSender))
        {
            break;
        }
    }
    if(iter == histories.end())
    {
        HistoryData newHistory;
        newHistory.m_currentUserId = msg.m_idSender;
        newHistory.m_friendUserId = msg.m_idReceiver;
        newHistory.m_historyData.push_back(msg);
        histories.push_back(newHistory);
    }
    else
    {
        iter->m_historyData.push_back(msg);
    }
}

void MockDataProvider::createMessageId(Message &msg)
{
    qDebug() << "MockDataProvider::createMessageId \n";
    static int msgId = 0;
    msgId++;
    msg.m_idMessage = msgId;
}

std::optional<HistoryData> MockDataProvider::getHistory(int firstUserId, int secondUserId, int size)
{
   qDebug() << "MockDataProvider::getHistory \n";
   auto iter = histories.end();
   for(iter = histories.begin();iter != histories.end(); iter++)
   {
       if((iter->m_currentUserId == firstUserId && iter->m_friendUserId == secondUserId) ||
               (iter->m_currentUserId == secondUserId && iter->m_friendUserId == firstUserId))
       {
           break;
       }
   }
   if(iter == histories.end())
   {
       qDebug() << "MockDataProvider::getHistory HISTORY NOT FOUND firstUserId " <<firstUserId << " secondUserId " << secondUserId << "\n";
       HistoryData history;
       history.m_friendUserId = secondUserId;
       history.m_currentUserId = firstUserId;
       return history; //Temporary fix
   }
   else
   {
       for(auto it = iter->m_historyData.begin();it != iter->m_historyData.end(); it++)
       {
            qDebug() << "MockDataProvider::getHistory data"<< it->m_textBody <<" \n";
       }
       return *iter;
   }
}

std::optional<UserStatus> MockDataProvider::getUserData(const LoginPackage &loginData)
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

const std::set<UserStatus>& MockDataProvider::getOnlineUsers()
{
    return std::set<UserStatus>();
}
