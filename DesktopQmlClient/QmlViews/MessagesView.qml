import QtQuick 2.12
import QtQuick.Controls 2.12
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

