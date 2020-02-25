import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle
{
    color : parent.color
    Rectangle
    {
        id : messageInputFieldButtons

        width: parent.width * 0.4
        height : 35

        color : parent.color

        anchors.top : parent.top
        anchors.topMargin: (parent.height - messageInputFieldButtons.height) / 2

        Rectangle
        {
            id : attachmentBtn

            width: 27
            height : parent.height

            anchors.left: parent.left
        }

        Rectangle
        {
            id : smilesBtn

            width: 30
            height: parent.height

            anchors.left : attachmentBtn.right
            anchors.leftMargin: 22
        }

        Rectangle
        {
            id : voiceMsgBtn

            width: 21
            height : parent.height

            anchors.left : smilesBtn.right
            anchors.leftMargin: 22
        }
    }

    Button
    {
        id: textInputButton

        height: parent.height
        width: parent.width * 0.6

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
