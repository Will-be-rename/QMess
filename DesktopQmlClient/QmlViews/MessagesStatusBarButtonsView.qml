import QtQuick 2.0

Rectangle
{

    Rectangle
    {
        id : searchBtn

        width: 30
        height: 35

        anchors.left: parent.left
    }

    Rectangle
    {
        id : messagesSettingsBtn

        width: 12
        height: 35

        anchors.left : searchBtn.right
        anchors.leftMargin: 61
    }
}
