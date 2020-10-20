#include "usermodel.h"
#include <QQmlEngine>
#include <QDebug>
UserModel::UserModel(): m_currentIndex(0)
{

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

    const User& user {(m_users.at(static_cast<int>(index.row())))};

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
        m_users.push_back({i,"User " + QString::number(i), static_cast<bool>(i%3)});
    }

}

QVariant UserModel::getUserName(int index)
{
    return QVariant::fromValue(m_users[index].getUserName());
}

void UserModel::selectionChanged(int index)
{
    m_currentIndex = index;
    emit userSelected();
}

void UserModel::addUser(const User& newUser)
{
    int index = 0;
    QModelIndex modelIndex;
    for(; index < m_users.size(); ++index)
    {
        if(m_users[index].getUserId() == newUser.getUserId())
        {
            m_users[index].setOnline(newUser.isOnline());
            modelIndex = createIndex(static_cast<int>(index), 0, nullptr);
            qDebug() << "Same user";
            break;
        }
    }
    if(index ==  m_users.size())
    {
        beginInsertRows(QModelIndex(),rowCount(), rowCount());
        m_users.push_back(newUser);
        endInsertRows();
        modelIndex = createIndex(rowCount(), 0, nullptr);
    }
    emit dataChanged(modelIndex, modelIndex);
}

int UserModel::getCurrentIndex() const
{
    return m_currentIndex;
}

const User& UserModel::getCurrentUser() const
{
    return m_users[m_currentIndex];
}

bool UserModel::isEmpty() const
{
    return m_users.empty();
}
