#ifndef MESSAGESMODEL_H
#define MESSAGESMODEL_H

#include <QAbstractListModel>
#include <vector>

#include "ViewModels/messageview.h"

class MessagesModel : public QAbstractListModel
{
    Q_OBJECT
public:
    MessagesModel();
    QHash<int, QByteArray> roleNames() const override;
    int rowCount(const QModelIndex& parent = {}) const override;
    QVariant data(const QModelIndex& index = {}, int role = Qt::DisplayRole) const override;
    void addMessage(const MessageView& newMessage);

private:
    std::vector <MessageView> m_messages;
    enum MessageRoles{
         TextBodyRole = Qt::UserRole + 1,
         DateRole,
         TimeRole,
         IsReceivedRole,
    };
};

#endif // MESSAGESMODEL_H
