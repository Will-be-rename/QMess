#include "chatwindow.h"
#include "ui_chatwindow.h"

#include <QDebug>
#include <QDate>
#include <QRandomGenerator>
ChatWindow::ChatWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::ChatWindow),
    m_EventProcessor()
{
    m_ui->setupUi(this);
    TcpDataProvider& dataProvider = m_EventProcessor.dataProvider();
    connect(&dataProvider, SIGNAL(newMessageDetected(Message)),
                     this, SLOT(newMessageRecievedSlot(Message)));
    connect(&dataProvider, SIGNAL(newUserStatusDetected(UserStatus)),
                     this, SLOT(userStatusChangedSlot(UserStatus)));

    QIcon ButtonIcon("://send.png");
    m_ui->sendButton->setIcon(ButtonIcon);
    m_ui->sendButton->setIconSize(QSize(95, 95));
    m_EventProcessor.processEvents();
}

ChatWindow::~ChatWindow()
{
    delete m_ui;
}

void ChatWindow::userStatusChangedSlot(UserStatus status)
{
    qDebug() << "userStatusChangedSlot id " << status.m_userId << " isOnline " << status.m_isOnline;
    int positionToUpdate = -1;
    for (int i = 0; i < DataStorage::getInstance().onlineUsers.size();i++)
    {
        if(DataStorage::getInstance().onlineUsers[i].m_userId == status.m_userId)
        {
            positionToUpdate = i;
        }
    }

    QListWidgetItem *item ;
    if(-1 == positionToUpdate)
    {
        DataStorage::getInstance().onlineUsers.push_back(status);
        item= new QListWidgetItem(m_ui->usersListWigdet);
    }
    else
    {
        item = m_ui->usersListWigdet->item(positionToUpdate);
    }

    item->setText(status.m_userName);

    if(status.m_isOnline)
    {
        item->setIcon(QIcon("://online.png"));
    }
    else
    {
        item->setIcon(QIcon("://offline.png"));
    }
    m_ui->usersListWigdet->addItem(item);
}

void ChatWindow::newMessageRecievedSlot(Message msg)
{
    qDebug() << "newMessageRecievedSlot";
    m_ui->mainTextBody->setText(msg.m_dateTime + "\t" + msg.m_textBody + "\n");
}

void ChatWindow::on_sendButton_clicked()
{
    qDebug() << "on_sendButton_clicked";
    Message msg;
    msg.m_textBody = m_ui->inputTextbox->text();
    msg.m_dateTime = QDate::currentDate().toString();
    msg.m_idMessage = QRandomGenerator::global()->generate();
    msg.m_idReceiver = 1;
    msg.m_idSender = 1;
    m_EventProcessor.sendMessage(msg);
    m_ui->inputTextbox->setText("");
}

void ChatWindow::on_usersListWigdet_itemClicked(QListWidgetItem *item)
{
    static_cast<void>(item);
    m_ui->mainTextBody->setText("");
    loadHistory(m_EventProcessor.m_cachedHistory.getChatHistory(static_cast<size_t>(m_ui->usersListWigdet->currentRow())));
    qDebug() << "on_usersListWigdet_itemClicked";
}

void ChatWindow::on_sendButton_pressed()
{
    QIcon ButtonIcon("://sendPressed.png");
    m_ui->sendButton->setIcon(ButtonIcon);
}

void ChatWindow::on_sendButton_released()
{
    QIcon ButtonIcon("://send.png");
    m_ui->sendButton->setIcon(ButtonIcon);
}

void ChatWindow::selectedUserHistoryUpdated(size_t userId)
{
    if(userId == DataStorage::getInstance().getCurrentUser().m_userId)
    {
        loadHistory(m_EventProcessor.m_cachedHistory.getChatHistory(userId));
    }
}

void ChatWindow::loadHistory(const QVector<QString>& newHistory)
{
    for(int i = 0 ; i < newHistory.size(); i++)
    {
        m_ui->mainTextBody->setText(m_ui->mainTextBody->toPlainText() + "\n" + newHistory[i]);
    }
}


