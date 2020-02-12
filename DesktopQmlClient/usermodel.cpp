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
        default:
        {
        return {};
        }
    }

}

void UserModel::registerMe(const std::string &moduleName)
{
    qmlRegisterType<UserModel>(moduleName.c_str(),1,0,"UserModel");
}

void UserModel::addUsers()
{
    m_users.push_back({0,"User 1 ", true});
    m_users.push_back({1,"Hello ", true});
    m_users.push_back({2,"Maksym ", false});
    m_users.push_back({3,"Ostrometskyi ", true});
    m_users.push_back({4,"Kak", true});
    m_users.push_back({5,"Tebe", false});
    m_users.push_back({6,"This", true});
    m_users.push_back({7,"Fucking", false});
    m_users.push_back({7,"List", true});
}
