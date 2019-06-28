#include "tcpdataprovider.h"

TcpDataProvider::TcpDataProvider()
{

}

void TcpDataProvider::sendMessage(QTcpSocket &socket, const Message &message)
{
    QByteArray data;
    QDataStream ds(&data, QIODevice::ReadWrite);
    ds.setVersion(QDataStream::Qt_5_11);
    ds << static_cast<int>(eMessage) << message;
    socket.write(data);
}

void TcpDataProvider::sendUserStatus(QTcpSocket &socket, const UserStatus &userStatus)
{
    QByteArray data;
    QDataStream ds(&data, QIODevice::ReadWrite);
    ds.setVersion(QDataStream::Qt_5_11);
    ds << static_cast<int>(eUserStatus) << userStatus;
    socket.write(data);
}

void TcpDataProvider::sendLoginPackage(QTcpSocket &socket, const UserStatus &loginData)
{
    QByteArray data;
    QDataStream ds(&data, QIODevice::ReadWrite);
    ds.setVersion(QDataStream::Qt_5_11);
    ds << static_cast<int>(-1) << loginData;
    socket.write(data);
}

void TcpDataProvider::getData(QTcpSocket &socket)
{

}
