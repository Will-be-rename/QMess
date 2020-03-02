import QtQuick 2.12
import QtQuick.Controls 2.12

Button
{
    Item
    {
        id: textInputButtonContent

        width: parent.width * 0.4
        height: 35

        anchors.centerIn: parent

        Image
        {
            id: textInputButtonLogo
            source: "../Resources/Images/send_button_logo.png"

            anchors.left: parent.left
        }

        Text
        {
            id: textInputButtonText

            anchors
            {
                top : parent.top
                topMargin: 8
                left: textInputButtonLogo.right
                leftMargin: 6
            }

            font.pixelSize: 18
            color: "#FFFFFF"

            text: qsTr("Send")
        }
    }
}
