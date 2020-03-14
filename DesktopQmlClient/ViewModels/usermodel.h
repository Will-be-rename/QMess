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
    Q_INVOKABLE void selectionChanged(int index);
    void addUser(const User& newUser);
    int getCurrentIndex() const;
    const User& getCurrentUser() const;
private:
    std::vector<User> m_users;
    int m_currentIndex;
    enum UserRoles{
         IdRole = Qt::UserRole + 1,
         NameRole,
         OnlineRole,
         IncommingMessages,
    };
     void addUsers(); // will be removed
};

#endif // USERMODEL_H
