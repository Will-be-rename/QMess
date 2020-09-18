import QtQuick 2.12
import QtQuick.Controls 2.12

Button
{
    id: tabButton
    width: 145
    height: 61

    font.family: "Roboto"
    font.bold: true
    font.pixelSize: 20

    contentItem: Text
    {
        text: tabButton.text
        font: tabButton.font
        color: tabButton.checked ?  "#777777" : "#FFFFFF"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    background: Rectangle
    {
        radius : 80
        color: checked ? "#C4C4C4" : "#B2AFAF"
    }
}
