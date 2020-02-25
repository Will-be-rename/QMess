import QtQuick 2.12

Rectangle
{
    color: "#CBCBCB"
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
        Text
        {
            id: textInputBackground
            height: parent.height
            width: parent.width * 0.75
            visible: true
            opacity: 0.2
            padding: 8
            font.family: parent.font.family
            font.pixelSize: parent.font.pixelSize
            font.italic: true
            text: "Enter text here..."
        }
    }

    MessagesInputFieldButtonsView
    {
        id: textInputFieldButtons

        height : parent.height
        width: parent.width * 0.25

        anchors.left: textInputField.right
    }
}
