import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle
{
    id: root

    property string underlineButtonText: ""
    property string placeholder: ""
    property url    iconSource:""
    property int    inputMethodHints: input.inputMethodHints
    property int    echoMode: input.echoMode

    width: 493
    height: 20

    color: parent.color

     TextInput {

        id: input

        width: root.width
        height: root.height

        layer.enabled: true

        color: "black" /*Qt.rgba(119, 119, 119, 0.43)*/

        font.family: "Roboto"
        font.pixelSize: 15

        anchors.bottom: underline.top

        onTextEdited:
        {
            placeholderItem.visible = text == ""
        }

        Text
        {
            id: placeholderItem

            width: root.width
            height:root.height

            visible: true
            font: parent.font

            color: input.color
            text : root.placeholder

            anchors.bottom: input.bottom
        }
    }

    Image
    {
        id: icon

        width: 30
        height:35

        anchors.left : input.right
        anchors.leftMargin: 14

        anchors.bottom: underline.top
        source: root.iconSource
    }

    Rectangle
    {
        id: underline

        width: root.width
        height: 1

        anchors.top: input.bottom

        color: "black"
    }

    Button {
        id: underlineTextItem

        background: Rectangle{ color: root.color }

        visible: underlineButtonText !== ""

        anchors.top : underline.bottom
        anchors.horizontalCenter: underline.horizontalCenter
        text: underlineButtonText
    }
}
