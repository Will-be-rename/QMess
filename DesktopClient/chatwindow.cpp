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
    connect(&m_EventProcessor, SIGNAL(newMessageRecieved()),
                     this, SLOT(newMessageRecievedSlot()));
    connect(&m_EventProcessor, SIGNAL(userStatusChanged()),
                     this, SLOT(userStatusChangedSlot()));

    m_EventProcessor.processEvents();
}

ChatWindow::~ChatWindow()
{
    m_EventProcessor.finish();
    delete m_ui;
}

void ChatWindow::userStatusChangedSlot()
{
    UserStatus status = DataStorage::getInstance().getUserStatus();
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
        item->setIcon(QIcon(":/online.png"));
    }
    else
    {
        item->setIcon(QIcon(":/offline.png"));
    }
    m_ui->usersListWigdet->addItem(item);
}

void ChatWindow::newMessageRecievedSlot()
{
    qDebug() << "newMessageRecievedSlot";
    Message msg = DataStorage::getInstance().getMessage();
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
    qDebug() << "on_usersListWigdet_itemClicked";
}
