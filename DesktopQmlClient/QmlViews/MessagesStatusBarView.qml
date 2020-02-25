import QtQuick 2.12

Rectangle
{
    color : "#CBCBCB"

    Rectangle
    {
        id: recepientLogoBtn

        width: 60
        height: 60
        color:"#FFFFFF"

        radius : 100

        anchors.top : parent.top
        anchors.topMargin : 14
        anchors.leftMargin : 33
        anchors.left : parent.left
    }

    Text {
        id: recepientName

        anchors.top : parent.top
        anchors.topMargin: 35
        anchors.left : recepientLogoBtn.right
        anchors.leftMargin: 26

        color: "#000000"

        text: qsTr("Recepient Name")
    }

    SearchFieldView
    {
        id : messageSearchField

        anchors.left : recepientName.right
        anchors.leftMargin: 655.5

        anchors.top : parent.top
        anchors.topMargin: 30
    }

    MessagesStatusBarButtonsView
    {
        id : messMessagesStatusBarButtons

        anchors.top : parent.top
        anchors.topMargin: 30

        anchors.left : messageSearchField.right
        anchors.leftMargin: 50
    }
}
