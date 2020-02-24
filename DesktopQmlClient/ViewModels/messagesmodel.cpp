#include "messagesmodel.h"

#include <QQmlEngine>

MessagesModel::MessagesModel()
{
    addMessages();
}

QHash<int, QByteArray> MessagesModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[MessagesModel::TextBodyRole] = "textBody";
    roles[MessagesModel::DateRole] = "date";
    roles[MessagesModel::TimeRole] = "time";
    roles[MessagesModel::IsReceivedRole] = "isReceived";
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

    const MessageView& message {(m_messages.at(static_cast<size_t>(index.row())))};

    switch(role)
    {
        case TextBodyRole:
        {
            return QVariant::fromValue(message.getTextBody());
        }
        case DateRole:
        {
            return QVariant::fromValue(message.getDate());
        }
        case TimeRole:
        {
            return QVariant::fromValue(message.getTime());
        }
        case IsReceivedRole:
        {
            return QVariant::fromValue(message.isReceived());
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
    m_messages.push_back({"Hello",QDateTime()});
    m_messages.push_back({"Lorem Ipsum - это текст-\"рыба\", часто используемый в печати и вэб-дизайне. Lorem Ipsum является стандартной \"рыбой\" для текстов на латинице с начала XVI века. В то время некий безымянный печатник создал большую коллекцию размеров и форм шрифтов, используя Lorem Ipsum для распечатки образцов.",QDateTime()});
}
