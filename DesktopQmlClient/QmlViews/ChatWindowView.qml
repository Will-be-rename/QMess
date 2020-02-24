import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle
{
    width : parent.width
    height : parent.height

    Rectangle
    {
        id: chatWindowUserList

        width: parent.width * 0.25
        height: parent.height

        Rectangle
        {
            id: userListStatusBar

            width: parent.width
            height: 58

            anchors.bottom: userListView.top

            color: "#9F9F9F"

            Rectangle
            {
                anchors.top : parent.top
                anchors.topMargin: 9

                Rectangle
                {
                    id: userListMenuBtn

                    width: 27
                    height: 35
                    color:"#707070"

                    anchors.left: parent.left
                    anchors.leftMargin: 24
                }

                SearchFieldView
                {
                    id: userListSearchField

                    anchors.left : userListMenuBtn.right
                    anchors.leftMargin: 27
                }
            }

        }


        UserListView
        {
            id: userListView

            width: parent.width
            height: chatWindowUserList.height - userListStatusBar.height
            color: "#94918E"

            anchors.top : userListStatusBar.bottom
        }

    }

    Rectangle
    {
        id: chatWindowMessagesList

        width: parent.width * 0.75
        height: parent.height

        anchors.left: chatWindowUserList.right

        Rectangle
        {
            id : messageListStatusBar

            width : parent.width
            height: 100

            color : "#CBCBCB"

            Rectangle
            {
                id: recepientLogoBtn

                width: 60
                height: 60
                color:"#FFFFFF"

                radius : 100

                anchors.top : parent.top
                anchors.topMargin : 14
                anchors.leftMargin : 33
                anchors.left : parent.left
            }

            Text {
                id: recepientName

                anchors.top : parent.top
                anchors.topMargin: 35
                anchors.left : recepientLogoBtn.right
                anchors.leftMargin: 26

                color: "#000000"

                text: qsTr("Recepient Name")
            }


            SearchFieldView
            {
                id : messageSearchField
                anchors.left : recepientName.right
                anchors.leftMargin: 655.5
                anchors.top : parent.top
                anchors.topMargin: 30
            }


            Rectangle
            {
                anchors.top : parent.top
                anchors.topMargin: 30

                anchors.left : messageSearchField.right
                anchors.leftMargin: 50

                Rectangle
                {
                    id : searchBtn

                    width: 30
                    height: 35

                    anchors.left: parent.left
                }

                Rectangle
                {
                    id : messagesSettingsBtn

                    width: 12
                    height: 35

                    anchors.left : searchBtn.right
                    anchors.leftMargin: 61
                }
            }
        }

        MessagesView
        {
            id : messagesListView

            width:  parent.width
            height: chatWindowMessagesList.height - messageListStatusBar.height - messageInput.height

            anchors.top: messageListStatusBar.bottom
            anchors.bottom: messageInput.top
        }

        Rectangle
        {
            id: messageInput
            width: parent.width
            height: 60
            color: "#CBCBCB"
            anchors.bottom: parent.bottom

            layer.enabled: true

            TextInput
            {
               id: textInputField

                height: parent.height
                width: parent.width * 0.75
                padding: 8
                font.family: "Helvetica"
                font.pixelSize: 32
                cursorVisible: textInputField.focus != false
                onTextEdited:
                {
                    textInputBackground.visible = text == ""
                }
            }
            Text
            {
                id: textInputBackground
                height: parent.height
                width: parent.width - attachmentBtn.width - smilesBtn.width - voiceMsgBtn.width - textInputButton.width
                visible: true
                opacity: 0.2
                padding: 8
                font.family: "Helvetica"
                font.pixelSize: 32
                font.italic: true
                text: "Enter text here..."
            }

            Rectangle
            {
                id : attachmentBtn

                width: 27
                height: 35

                anchors.right: smilesBtn.left
                anchors.rightMargin: 22
                anchors.top : parent.top
                anchors.topMargin: 6
            }

            Rectangle
            {
                id : smilesBtn

                width: 30
                height: 35

                anchors.right : voiceMsgBtn.left
                anchors.rightMargin: 22
                anchors.top : parent.top
                anchors.topMargin: 6
            }

            Rectangle
            {
                id : voiceMsgBtn

                width: 21
                height: 35

                anchors.right : textInputButton.left
                anchors.rightMargin: 35
                anchors.top : parent.top
                anchors.topMargin: 6
            }

            Button
            {
                id: textInputButton

                height: parent.height
                width: parent.width * 0.1
                anchors.right: parent.right
                text: "Send"
                highlighted: true
                onClicked:
                {
                    textInputField.text = ""
                    textInputBackground.visible = true
                }
            }

        }
    }
}
