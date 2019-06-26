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

    QIcon ButtonIcon("://send.png");
    m_ui->sendButton->setIcon(ButtonIcon);
    m_ui->sendButton->setIconSize(QSize(95, 95));
    m_EventProcessor.processEvents();
}

ChatWindow::~ChatWindow()
{
    m_EventProcessor.finish();
    delete m_ui;
}

void ChatWindow::userStatusChangedSlot()
{
    qDebug() << "userStatusChangedSlot";
    m_ui->mainTextBody->setText("userStatusChangedSlot");
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
