#ifndef CACHEDMESSAGEHISTORY_H
#define CACHEDMESSAGEHISTORY_H
#include "models.h"

#include <map>

#include <QVector>
class CachedMessageHistory
{
public:
    CachedMessageHistory();
    void fillChatHistoty(size_t userId, QVector<QString> chatData);
    void addMessage(const Message& newMessage);
    QVector<QString> getChatHistory(size_t userId);
    std::map<size_t, QVector<QString>> usersHistoryMap;
};

#endif // CACHEDMESSAGEHISTORY_H
