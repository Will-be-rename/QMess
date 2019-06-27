#include "cachedmessagehistory.h"

CachedMessageHistory::CachedMessageHistory()
{

}

void CachedMessageHistory::fillChatHistoty(size_t userId, QVector<QString> chatData)
{

}

void CachedMessageHistory::addMessage(const Message &newMessage)
{

}

QVector<QString> CachedMessageHistory::getChatHistory(size_t userId)
{
    return this->usersHistoryMap[userId];
}
