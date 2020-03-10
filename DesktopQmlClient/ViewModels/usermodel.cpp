#include "usermodel.h"
#include <QQmlEngine>

UserModel::UserModel()
{
    addUsers();
}

QHash<int, QByteArray> UserModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[UserRoles::IdRole] = "userId";
    roles[UserRoles::NameRole] = "name";
    roles[UserRoles::OnlineRole] = "online";
    roles[UserRoles::IncommingMessages] = "incommingMessages";
    return roles;
}

int UserModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)
    return static_cast<int>(m_users.size());
}

QVariant UserModel::data(const QModelIndex& index, int role) const
{
    if(!index.isValid() || index.row() >= rowCount(index))
    {
        return {};
    }

    const User& user {(m_users.at(static_cast<size_t>(index.row())))};

    switch(role)
    {
        case IdRole:
        {
            return QVariant::fromValue(user.getUserId());
        }
        case NameRole:
        {
            return QVariant::fromValue(user.getUserName());
        }
        case OnlineRole:
        {
            return QVariant::fromValue(user.isOnline());
        }
        case IncommingMessages:
        {
            return QVariant::fromValue(user.getIncommningMessages());
        }
        default:
        {
        return {};
        }
    }

}

void UserModel::addUsers()
{
    for(int i = 0 ; i < 100; i++)
    {
        m_users.push_back({i,"User " + QString::number(i), i%3});
    }

}

QVariant UserModel::getUserName(int index)
{
    return QVariant::fromValue(m_users[index].getUserName());
}

void UserModel::selectionChanged(int index)
{

}

