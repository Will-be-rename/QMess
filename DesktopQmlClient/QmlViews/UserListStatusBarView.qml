import QtQuick 2.12

Rectangle
{
    color: "#9F9F9F"
    Rectangle
    {
        anchors.top : parent.top
        anchors.topMargin: 9

        Rectangle
        {
            id: userListMenuBtn

            width: 27
            height: 35
            color:"#707070"

            anchors.left: parent.left
            anchors.leftMargin: 24
        }

        SearchFieldView
        {
            id: userListSearchField

            anchors.left : userListMenuBtn.right
            anchors.leftMargin: 27
        }
    }
}

