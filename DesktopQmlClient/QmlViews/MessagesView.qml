import QtQuick 2.12
import QtQuick.Controls 2.12
import Messages 1.0

Rectangle
{
    width: parent.width * 0.75
    height: parent.height
    color: "#ffe4c4"

    Rectangle
    {
        id: statusBarRectangle

        width: parent.width
        height: 60
        color: "#fff0f5"
        z:1
        Text
        {
            leftPadding: font.pixelSize / 2
            font.family: "Helvetica"
            color: "#000f0b"
            font.pixelSize: 40
            text: "should be fixed"// UserModel.getUserName(userListView.currentIndex)

        }
    }
    Rectangle
    {
        id: messagesRectangle
        width:  parent.width
        height: parent.height - statusBarRectangle.height - textinputRectangle.height
        anchors.top: statusBarRectangle.bottom
        anchors.bottom: textinputRectangle.top
        anchors.left: mainWindow.left
        color: "#a3a3a3"
        Component
        {
            id: messagesDelegate

            Row
            {
                topPadding: 25
                leftPadding: 34
                rightPadding: 945
                ItemDelegate
                {
                    width: 300
                    implicitHeight: Math.max(rowText.implicitHeight)
                    MouseArea
                    {
                        hoverEnabled: false
                        anchors.fill: parent
                        onClicked:
                        {
                        }
                    }
                    contentItem :
                    Item
                    {
                        anchors.fill: parent
                        Rectangle
                        {
                            id: contactIcon
                            height: 60
                            width: 60
                            color: "white"
                            radius: width * 0.5
                        }
                        Rectangle
                        {
                            anchors.top: parent.top
                            anchors.left:contactIcon.right
                            anchors.leftMargin: 28
                            implicitHeight: Math.max(rowText.implicitHeight)
                            width: 376
                            color: "#d4d4d4"
                            radius: width * 0.1
                            Text
                            {
                                id: rowText
                                anchors.top: parent.top
                                anchors.left: parent.left
                                topPadding: 20
                                leftPadding: 24
                                bottomPadding: 22
                                rightPadding: 60
                                text: textBody
                                font.family: "Font Awesome 5"
                                color: "white"
                                font.pixelSize: 16
                                width: parent.width
                                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                            }
                        }
                    }

                }
            }
        }
        ListView
        {
            id: messagesListView
            currentIndex: 0
            anchors.fill: parent
            anchors.topMargin: 20
            highlightFollowsCurrentItem: false
            model: MessagesModel
            {
                id: messagesList
            }
            delegate: messagesDelegate
            spacing: 1
            focus: false
         }
    }
    Rectangle
    {
        id: textinputRectangle
        width: parent.width
        height: 60
        color: "#fff0f5"
        anchors.bottom: parent.bottom
        TextInput
        {
           id: textInputField

            height: parent.height
            width: parent.width * 0.9
            padding: 8
            font.family: "Helvetica"
            font.pixelSize: 32
            font.italic: true
            cursorVisible: true
            focus: true
            onTextEdited:
            {
                text == "" ? textInputBackground.visible = true : textInputBackground.visible = false
            }
        }
        Text
        {
            id: textInputBackground
            height: parent.height
            width: parent.width * 0.9
            visible: true
            opacity: 0.2
            padding: 8
            font.family: "Helvetica"
            font.pixelSize: 32
            font.italic: true
            text: "Enter text here..."
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

