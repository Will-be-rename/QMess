#ifndef USERMODEL_H
#define USERMODEL_H

#include <QAbstractListModel>
#include <vector>
#include <string>

#include "user.h"

class UserModel : public QAbstractListModel
{
    Q_OBJECT
public:
    UserModel();
    QHash<int, QByteArray> roleNames() const override;
    int rowCount(const QModelIndex& parent = {}) const override;
    QVariant data(const QModelIndex& index = {}, int role = Qt::DisplayRole) const override;
    Q_INVOKABLE QVariant getUserName(int index);
    static void registerMe(const std::string& moduleName);
    void selectionChanged(int index);
private:
    std::vector<User> m_users;
    enum UserRoles{
         IdRole = Qt::UserRole + 1,
         NameRole,
         OnlineRole,
         IncommingMessages,
    };
     void addUsers(); // will be removed
};

#endif // USERMODEL_H
