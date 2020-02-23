#ifndef MESSAGESMODEL_H
#define MESSAGESMODEL_H

#include <QAbstractListModel>
#include <vector>

#include "models.h"

class MessagesModel : public QAbstractListModel
{
public:
    MessagesModel();
    QHash<int, QByteArray> roleNames() const override;
    int rowCount(const QModelIndex& parent = {}) const override;
    QVariant data(const QModelIndex& index = {}, int role = Qt::DisplayRole) const override;
    static void registerMe(const std::string& moduleName);
    void addMessages(); //will be removed

private:
    std::vector <Message> m_messages;
    enum MessageRoles{
         IdRole = Qt::UserRole + 1,
         SenderRole,
         ReceiverRole,
         TextRole,
         DateTimeRole,
    };
};

#endif // MESSAGESMODEL_H
