#include "messagesmodel.h"

#include <QQmlEngine>
#include <QDebug>
MessagesModel::MessagesModel()
{
}

QHash<int, QByteArray> MessagesModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[MessagesModel::TextBodyRole] = "textBody";
    roles[MessagesModel::DateRole] = "date";
    roles[MessagesModel::TimeRole] = "time";
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

    const MessageView& message {(m_messages.at(static_cast<int>(index.row())))};

    switch(role)
    {
        case TextBodyRole:
        {
            return QVariant::fromValue(message.getTextBody());
        }
      /*  case DateRole:
        {
            return QVariant::fromValue(message.getDate());
        }
        case TimeRole:
        {
            return QVariant::fromValue(message.getTime());
        }*/
        default:
        {
        return {};
        }
    }

}

void MessagesModel::addMessage(const MessageView& newMessage)
{
    beginInsertRows(QModelIndex(),rowCount(), rowCount());
    m_messages.push_back(newMessage);
    endInsertRows();
    QModelIndex index = createIndex(rowCount(), 0, nullptr);
    emit dataChanged(index, index);
}

void MessagesModel::sendMessage(const QString& messageText)
{
    if(false == messageText.isEmpty())
    {
        qDebug()<<"Send message " << messageText;
        emit messageIsSent(messageText);
    }
}

