#include "chatwindow.h"
#include "ui_chatwindow.h"

#include <QDebug>
#include <functional>

ChatWindow::ChatWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::ChatWindow),
    m_EventProcessor(),
    m_Worker()
{
    m_ui->setupUi(this);
    auto threadWorker = [this](EventMessageProcessor& eventProcessor){eventProcessor.processEvents();};
    m_Worker = std::async(std::launch::async, threadWorker, std::ref(m_EventProcessor));

    connect(&m_EventProcessor, SIGNAL(newMessageRecieved()),
                     this, SLOT(newMessageRecievedSlot()));
    connect(&m_EventProcessor, SIGNAL(userStatusChanged()),
                     this, SLOT(userStatusChangedSlot()));

}

ChatWindow::~ChatWindow()
{
    m_EventProcessor.finish();
    m_Worker.get();
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
    m_ui->mainTextBody->setText("newMessageRecievedSlot");
}

void ChatWindow::on_sendButton_clicked()
{
    qDebug() << "on_sendButton_clicked";
}

void ChatWindow::on_usersListWigdet_itemClicked(QListWidgetItem *item)
{
    qDebug() << "on_usersListWigdet_itemClicked";
}
