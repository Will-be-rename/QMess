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
        color: "#adcaf7"
        border.color: "#d3d3d3"
        border.width: 4
        /*ListModel {
            id: onlineUsersList

            ListElement {
                userId: 1
                name: "User test"
                online: false
            }
            ListElement {
                userId: 2
                name: "test user 55"
                online: true
            }
            ListElement {
                userId: 3
                name: "third user"
                online: true
            }
            ListElement {
                userId: 4
                name: "next user"
                online: true
            }
            ListElement {
                userId: 6
                name: "not advanced c++"
                online: true
            }
            ListElement {
                userId: 7
                name: "7 User test"
                online: false
            }
            ListElement {
                userId: 8
                name: "8 test user 55"
                online: true
            }
            ListElement {
                userId: 9
                name: "9 third user"
                online: true
            }
            ListElement {
                userId: 10
                name: "10 next user"
                online: true
            }
            ListElement {
                userId: 11
                name: "now advanced c++"
                online: true
            }
            ListElement {
                userId: 12
                name: "some"
                online: false
            }
            ListElement {
                userId: 13
                name: "more"
                online: true
            }
            ListElement {
                userId: 14
                name: "elements"
                online: true
            }
            ListElement {
                userId: 15
                name: "in fucking"
                online: true
            }
            ListElement {
                userId: 16
                name: "qml list"
                online: true
            }
        } */
        Component
        {
            id: userDelegate
            Row
            {
                padding: 5
                spacing: 100

                Rectangle
                {
                    id: rowRectangle

                    color: "#3f81e8"
                    width: 460
                    height: 60
                    border.width: 5
                    border.color: "#8c97a8"
                    radius: 5
                    Text
                    {
                        leftPadding: font.pixelSize / 2
                        text: name
                        font.family: "Helvetica"
                        color: "#383838"
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
                            rowRectangle.color = "#896db0"
                        }
                        onExited:
                        {
                            rowRectangle.color = "#3f81e8"
                        }

                    }
                }
            }
        }

        ListView
        {
            id: userListView

            anchors.fill: parent
            model: UserModel
            {

            }
            delegate: userDelegate
            focus: true
            highlight:
                        Rectangle
                        {
                            width: 400
                            height: 40
                            color: "#896db0"
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
                text: onlineUsersList.get(userListView.currentIndex).name

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
               id: textIntupField

                height: parent.height
                width: parent.width * 0.9
                padding: 8
                font.family: "Helvetica"
                font.pixelSize: 32
                font.italic: true
                text: "Enter text here..."
                opacity: 0.2
                cursorVisible: true
                focus: true
                MouseArea
                {
                    id: mouseInput

                    anchors.fill: parent
                    hoverEnabled: true
                    onClicked:
                    {
                        textIntupField.text = ""
                        textIntupField.opacity = 1.0
                    }

                }
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
                    textIntupField.opacity = 0.2
                    textIntupField.text = "Enter text here..."
                }
            }
        }
    }
}
