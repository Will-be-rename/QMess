import QtQuick 2.12
import QtQuick.Controls 2.12
Rectangle
{
    id : root
    color: "#9F9F9F"
    Rectangle
    {
        anchors.top : parent.top
        anchors.topMargin: 9

        Button
        {
            id: userListMenuButton

            width: 27
            height: 35
            background: Rectangle { color: root.color }

            Image {
                id: userSettingsLogo
                source: "../Resources/Images/usr_list_settings_btn_logo.png"
                anchors.centerIn: parent
            }

            anchors.left: parent.left
            anchors.leftMargin: 24
        }

        SearchFieldView
        {
            id: userListSearchField

            anchors.left : userListMenuButton.right
            anchors.leftMargin: 27
        }
    }
}

