import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle
{
    id : root
    color : parent.color
    Rectangle
    {
        id : messageInputFieldButtons

        width: parent.width * 0.4
        height : 35

        color : root.color

        anchors.top : parent.top
        anchors.topMargin: (parent.height - messageInputFieldButtons.height) / 2

        InputFieldAttachmentButtonView
        {
            id : attachmentButton

            anchors.left: parent.left

            background: Rectangle { color: root.color }
        }

        InputFieldSmilesButtonView
        {
            id : smilesButton

            anchors
            {
                left: attachmentButton.right
                leftMargin : 22
            }

            background: Rectangle { color : root.color }
        }

        InputFieldVoiceMessageButtonView
        {
            id : voiceMsgButton

            anchors.left : smilesButton.right
            anchors.leftMargin: 22

            background: Rectangle { color : root.color }
        }
    }

    InputFieldSendMessageButtonView
    {
        id: textInputButton

        height: parent.height
        width: parent.width * 0.6

        anchors.right: parent.right
        highlighted: true
        onClicked:
        {
            messagesModel.sendMessage(textInputField.text)
            textInputField.text = ""
            textInputBackground.visible = true
        }
    }
}
