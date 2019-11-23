#ifndef DATASRORAGE_H
#define DATASRORAGE_H

#include <QVector>

#include "sessionclient.h"

class DataStorage
{
public:
    static DataStorage* getInstance();
    QVector<SessionClient*>& getSessionClients();
private:
    DataStorage();
    QVector<SessionClient*> m_clients;
};

#endif // DATASRORAGE_H
