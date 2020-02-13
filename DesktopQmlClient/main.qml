import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import Users 1.0

Window {
    id: mainWindow

    visible: true
    width: 1920
    height: 1080
    title: qsTr("MainWindow")
    Rectangle
    {
        id: listRectangle

        width: parent.width / 4
        height: parent.height
        color: "#B5D6BE"

        Component
        {
            id: userDelegate   
            Row
            {

                anchors.bottomMargin: 10
                Rectangle
                {
                    id: rowRectangle
                    color: "#dff5e5"
                    width: 480
                    height: 60
                    opacity: 0.8
                    Text
                    {
                        leftPadding: font.pixelSize / 2
                        text: name
                        font.family: "Helvetica"
                        font.pixelSize: 48
                    }
                    Rectangle
                    {
                         width: 25
                         height: 25
                         anchors.bottom: parent.bottom
                         color: online ? "green" : "gray"
                         border.color: "#0a2f4a"
                         border.width: 3
                         radius: width*0.5
                    }
                    MouseArea
                    {
                        id: mouse

                        anchors.fill: parent
                        hoverEnabled: true

                        onClicked: userListView.currentIndex = index
                        onEntered:
                        {
                            rowRectangle.color = "#A6F4ED"
                        }
                        onExited:
                        {
                            rowRectangle.color = "#dff5e5"
                        }

                    }
                }
            }
        }

        ListView
        {
            id: userListView
            currentIndex: 0
            anchors.fill: parent
            highlightFollowsCurrentItem: false
            model: UserModel
            {
                id: onlineUsersList
            }
            delegate: userDelegate
            spacing: 1
            focus: true
            highlight:
                Row
                {
                        Rectangle
                        {
                            color: "#4b97fa"
                            width: 480
                            height: 60
                            radius: 5
                            y:  userListView.currentItem.y
                        }
                }
        }

    }
    Rectangle
    {
        width: parent.width * 0.75
        height: parent.height
        color: "#ffe4c4"
        anchors.left: listRectangle.right
        Rectangle
        {
            id: statusBarRectangle

            width: parent.width
            height: 60
            color: "#fff0f5"
            Text
            {
                leftPadding: font.pixelSize / 2
                font.family: "Helvetica"
                color: "#000f0b"
                font.pixelSize: 40
                text: onlineUsersList.getUserName(userListView.currentIndex)

            }
        }
        Rectangle
        {
            width:  parent.width
            height: parent.height - statusBarRectangle.height - textinputRectangle.height
            anchors.top: statusBarRectangle.bottom
            anchors.bottom: textinputRectangle.top
            anchors.left: mainWindow.left
            color: "#d3d3d3"
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
}
