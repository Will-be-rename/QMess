#pragma once

#include <QByteArray>

class IEncryptor
{
public:
    virtual QByteArray encryptData(const QByteArray& data) = 0;
    virtual QByteArray decryptData(const QByteArray& data) = 0;
    virtual ~IEncryptor(){}
};
