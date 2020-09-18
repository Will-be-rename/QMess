import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle {
    id: root

    property bool isSignInContentActive: signInTab.checked
    signal minimizeClicked()
    signal closeClicked()
    signal positionChanged(point position)

    width: parent.width
    height: parent.height
    color: parent.color

    MouseArea
    {
        /* TODO: there's a small insensitive area on the top above the buttons */
        id: dragArea
        property point mouseClickPosition: "1,1"

        anchors.fill:parent
        drag.target: root

        onPressed: {
            mouseClickPosition = Qt.point(mouse.x, mouse.y)
        }

        onPositionChanged:
        {
            root.positionChanged(Qt.point(mouse.x - mouseClickPosition.x, mouse.y - mouseClickPosition.y));
        }
    }

    Rectangle
    {
        id: imageArea
        width: root.width * 0.5
        height: root.height
        color: parent.color
        Image
        {
            id: image
            anchors.centerIn: imageArea
            source: "../Resources/Images/login_image.png"
        }
    }
    Rectangle
    {
        id: buttonsArea

        width: parent.width * 0.5
        height: parent.height

        color:parent.color

        anchors.left: imageArea.right

        Button
        {
            id: closeWindowButton
            width: 21
            height: 35

            anchors.top: parent.top
            anchors.topMargin: 32
            anchors.right: parent.right

            background: Rectangle { color : root.color }

            Image {
                id: closeButtonLogo
                anchors.centerIn: parent
                source: "../Resources/Images/login_close_btn_logo.png"
            }
            onClicked:
            {
                root.closeClicked();
            }
        }

        Button
        {
            id: expandWindowButton
            width: 25
            height: 29

            anchors.top: parent.top
            anchors.topMargin: 37
            anchors.right: closeWindowButton.left
            anchors.rightMargin: 40

            background: Rectangle { color : root.color }

            Image {
                id: expandButtonLogo
                anchors.centerIn: parent
                source: "../Resources/Images/login_expand_btn_logo.png"
            }
        }

        Button
        {
            id: minimizeWindowButton
            width: 27
            height: 35

            anchors.top: parent.top
            anchors.topMargin: 36
            anchors.right: expandWindowButton.left
            anchors.rightMargin: 34

            background: Rectangle { color : root.color }

            Image {
                id: minimizeButtonLogo
                anchors.centerIn: parent
                source: "../Resources/Images/login_minimize_btn_logo.png"
            }
            onClicked:
            {
                root.minimizeClicked()
            }
        }

        Text {
            id: onlineText
            font.family: "Roboto"
            font.bold: true
            font.pixelSize: 40

            color: "#F8F8F8"
            text: qsTr("Online")
            anchors.left: buttonsArea.left
            anchors.leftMargin: 71
            anchors.top: parent.top
            anchors.topMargin: 86
        }

        LoginMenuTabButton
        {
            id: signInTab

            checked: true

            anchors.left: buttonsArea.left
            anchors.bottom: buttonsArea.bottom

            text: qsTr("Sign In")

            onClicked:
            {
                checked = true
                signUpTab.checked = false
            }
        }

        LoginMenuTabButton
        {
            id: signUpTab

            anchors.left: signInTab.right
            anchors.bottom: buttonsArea.bottom

            text: qsTr("Sing Up")

            onClicked:
            {
                checked = true
                signInTab.checked = false
            }
        }
    }
}
