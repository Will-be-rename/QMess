#include "messagesmodel.h"

#include <QQmlEngine>

MessagesModel::MessagesModel()
{
    addMessages();
}

QHash<int, QByteArray> MessagesModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[MessagesModel::IdRole] = "messageId";
    roles[MessagesModel::SenderRole] = "senderId";
    roles[MessagesModel::ReceiverRole] = "receiverId";
    roles[MessagesModel::TextRole] = "textBody";
    roles[MessagesModel::DateTimeRole] = "dateTime";

    return roles;
}

int MessagesModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)
    return static_cast<int>(m_messages.size());
}

QVariant MessagesModel::data(const QModelIndex& index, int role) const
{
    if(!index.isValid() || index.row() >= rowCount(index))
    {
        return {};
    }

    const Message& message {(m_messages.at(static_cast<size_t>(index.row())))};

    switch(role)
    {
        case IdRole:
        {
            return QVariant::fromValue(message.m_idMessage);
        }
        case SenderRole:
        {
            return QVariant::fromValue(message.m_idSender);
        }
        case ReceiverRole:
        {
            return QVariant::fromValue(message.m_idReceiver);
        }
        case TextRole:
        {
            return QVariant::fromValue(message.m_textBody);
        }
        case DateTimeRole:
        {
            return QVariant::fromValue(message.m_dateTime);
        }
        default:
        {
        return {};
        }
    }

}

void MessagesModel::registerMe(const std::string &moduleName)
{
    qmlRegisterType<MessagesModel>(moduleName.c_str(),1,0,"MessagesModel");
}


void MessagesModel::addMessages()
{
    m_messages.push_back({1,2,3,"Hello",""});
    m_messages.push_back({1,2,3,"How difficult was to create this fucking model!!!",""});
}
