import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle
{
    id : root
    color : parent.color
    Button
    {
        id : searchButton

        width: 30
        height: 35

        background: Rectangle { color : root.color }

        Image
        {
            id: searchButtonLogo
            source: "../Resources/Images/msg_search_btn_logo.png"
            anchors.centerIn: parent
        }

        anchors.left: parent.left
    }

    Button
    {
        id : messagesSettingsButton

        width: 12
        height: 35

        background: Rectangle { color : root.color }

        Image
        {
            id: messageSettingsButtonLogo
            source: "../Resources/Images/msg_settings_btn_logo.png"
            anchors.centerIn: parent
        }

        anchors.left : searchButton.right
        anchors.leftMargin: 61
    }
}
