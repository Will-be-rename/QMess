#ifndef TCPDATAPROVIDER_H
#define TCPDATAPROVIDER_H

#include <QTcpSocket>
#include <QObject>
#include "models.h"

class TcpDataProvider : public QObject
{
    Q_OBJECT
public:
    explicit TcpDataProvider(QTcpSocket* socket);
    void sendData(const Message& message);
    void sendData(const UserStatus& message);
    void sendData(const LoginPackage& loginpackge);
    void sendData(const HistoryDataRequest& history);
    void getData();
signals :
    void newMessageDetected(const Message& message);
    void newUserStatusDetected(const UserStatus& message);
    void currentUserDetected(const UserStatus& userStatus);
    void chatHistoryUpdated(const HistoryData& historyData);
private:
    QTcpSocket* m_socket;
};

#endif // TCPDATAPROVIDER_H
