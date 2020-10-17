#pragma once

#include <QTcpSocket>
#include <QObject>

#include <memory>

#include "models.h"
#include "iencryptor.h"

enum EncryptType
{
    MD5
};
class TcpDataProvider : public QObject
{
    Q_OBJECT
public:
    explicit TcpDataProvider(QTcpSocket& socket, EncryptType);
    void sendData(const Message& message);
    void sendData(const UserStatus& message);
    void sendData(const LoginPackage& loginpackge);
    void sendData(const HistoryDataRequest& history);
    void geAllData();
signals :
    void newMessageDetected(const Message& message);
    void newUserStatusDetected(const UserStatus& message);
    void currentUserDetected(const UserStatus& userStatus);
    void chatHistoryUpdated(const HistoryData& historyData);
private:

    QTcpSocket& m_socket;
    std::shared_ptr<IEncryptor> m_encryptor;
};
