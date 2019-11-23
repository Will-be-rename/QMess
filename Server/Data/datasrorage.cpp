#include "datasrorage.h"

DataStorage *DataStorage::getInstance()
{
    static DataStorage* instance = new DataStorage();
    return instance;
}

QVector<SessionClient *> &DataStorage::getSessionClients()
{
    return m_clients;
}

DataStorage::DataStorage() : m_clients()
{

}
