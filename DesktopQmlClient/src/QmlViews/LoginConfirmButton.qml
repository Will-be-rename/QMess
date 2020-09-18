import QtQuick 2.0
import QtQuick.Controls 2.12

Button
{
    id: confirmButton
    width: 206
    height: 74

    contentItem: Text {
        id: content

        text: confirmButton.text

        font.family: "Roboto"
        font.bold: true
        font.pixelSize: 20
        color: "white"

        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    background: Rectangle
    {
        radius: 70
        color: "#787878"
    }
}
