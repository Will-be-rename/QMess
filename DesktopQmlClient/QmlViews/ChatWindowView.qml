import QtQuick 2.12


Rectangle
{
    width : parent.width
    height : parent.height

    Rectangle
    {
        id: chatWindowUserList

        width: parent.width * 0.25
        height: parent.height

        UserListStatusBarView
        {
            id: userListStatusBar

            width: parent.width
            height: 58

            anchors.bottom: userListView.top
        }

        UserListView
        {
            id: userListView

            width: parent.width
            height: chatWindowUserList.height - userListStatusBar.height

            anchors.top : userListStatusBar.bottom
        }
    }

    Rectangle
    {
        id: chatWindowMessagesList

        width: parent.width * 0.75
        height: parent.height

        anchors.left: chatWindowUserList.right

        MessagesStatusBarView
        {
            id : messageListStatusBar

            width : parent.width
            height: 100
        }

        MessagesView
        {
            id : messagesListView

            width:  parent.width
            height: chatWindowMessagesList.height - messageListStatusBar.height - messageInput.height

            anchors.top: messageListStatusBar.bottom
            anchors.bottom: messageInput.top
        }

        MessagesInputFieldView
        {
            id: messageInput

            width: parent.width
            height: 60

            anchors.bottom: parent.bottom
        }
    }
}
