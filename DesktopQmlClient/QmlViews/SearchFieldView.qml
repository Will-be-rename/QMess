import QtQuick 2.12

Rectangle {

    width: 376
    height: 40

    color: "#FFFFFF"
    border.color: "#707070"
    radius: 100

    TextInput
    {
        id: searchFieldInput

        width: parent.width * .9
        height: parent.height

        anchors.top  : parent.top
        anchors.left : parent.left
        anchors.topMargin  : 10
        anchors.leftMargin : 19

        font.family: "Helvetica"
        font.pixelSize: 16
        font.italic: false
        color: "black"

        cursorVisible: searchFieldInput.focus != false
        onTextEdited:
        {
            searchFieldPlaceholder.visible = text == ""
        }

        layer.enabled: true

        Text
        {
            id: searchFieldPlaceholder

            width: parent.width
            height: parent.height

            font.family: parent.font.family
            font.pixelSize: parent.font.pixelSize
            font.italic: true

            color: Qt.rgba(0, 0, 0, 0.50)

            text: qsTr("Search...")
        }
    }
}
