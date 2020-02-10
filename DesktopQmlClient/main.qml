import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 1920
    height: 1080
    title: qsTr("MainWindow")
    Rectangle
    {
        width: parent.width / 4
        height: parent.height
        color: "#adcaf7"
        ListModel {
            id: onlineUsersList

            ListElement {
                userId: 1
                name: "User 123"
                online: false
            }
            ListElement {
                userId: 2
                name: "User 324"
                online: true
            }
            ListElement {
                userId: 3
                name: "User 324"
                online: true
            }
            ListElement {
                userId: 4
                name: "User 324"
                online: true
            }
            ListElement {
                userId: 6
                name: "User 324"
                online: true
            }
        }
        Component
        {
            id: userDelegate
            Row
            {
                padding: 10
                spacing: 100
                Rectangle
                {
                    color: "#3f81e8"
                    width: 460
                    height: 60
                    border.width: 5
                    border.color: "#8c97a8"
                    radius: 5
                    Text
                    {
                        text: "  " + name
                        font.family: "Helvetica"
                        color: "#383838"
                        font.pixelSize: 48
                    }
                    Rectangle
                    {
                         width: 30
                         height: 30
                         anchors.bottom: parent.bottom
                         color: online ? "green" : "gray"
                         border.color: "#0a2f4a"
                         border.width: 3
                         radius: width*0.5
                    }
                }
            }
        }

        ListView
        {
            anchors.fill: parent
            model: onlineUsersList
            delegate: userDelegate
            focus: true
            highlight:
            Rectangle
            {
                width: 380
                height: 40
                color: "#896db0"
            }
        }
    }
}
