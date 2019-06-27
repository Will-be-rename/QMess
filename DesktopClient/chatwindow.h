#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QMainWindow>
#include <QListWidget>

#include "eventmessageprocessor.h"

namespace Ui {
class ChatWindow;
}

class ChatWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChatWindow(QWidget *parent = nullptr);
    ~ChatWindow();
private slots:
    void userStatusChangedSlot  ();
    void newMessageRecievedSlot ();
    void on_sendButton_clicked();
    void on_usersListWigdet_itemClicked(QListWidgetItem *item);
    void on_sendButton_pressed();
    void on_sendButton_released();
    void selectedUserHistoryUpdated(size_t userId);

private:
    void loadHistory(const QVector<QString>& newHistory);
    Ui::ChatWindow*             m_ui;
    EventMessageProcessor       m_EventProcessor;
};

#endif // CHATWINDOW_H
