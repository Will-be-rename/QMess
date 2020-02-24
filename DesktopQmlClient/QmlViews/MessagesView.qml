import QtQuick 2.12
import QtQuick.Controls 2.12
import Messages 1.0

Rectangle
{
    id: messagesRectangle

    color: "#a3a3a3"
    Component
    {
        id: messagesDelegate

        Row
        {
            topPadding: 32
            leftPadding: 34
            rightPadding: 945
            bottomPadding: 15
            ItemDelegate
            {
                width: 300
                height: messagesRectangle.height * 0.05
                MouseArea
                {
                    hoverEnabled: false
                    anchors.fill: parent
                    onClicked:
                    {
                    }
                }
                contentItem :
                Item
                {
                    anchors.fill: parent
                    Rectangle
                    {
                        id: contactIcon
                        height: 60
                        width: 60
                        color: "white"
                        radius: width * 0.5
                    }
                    Rectangle
                    {
                        anchors.top: parent.top
                        anchors.left:contactIcon.right
                        anchors.leftMargin: 28
                        implicitHeight: Math.max(rowText.implicitHeight)
                        width: 376
                        color: "#d4d4d4"
                        radius: width * 0.1
                        Text
                        {
                            id: rowText
                            anchors.top: parent.top
                            anchors.left: parent.left
                            topPadding: 20
                            leftPadding: 24
                            bottomPadding: 22
                            rightPadding: 60
                            text: textBody
                            font.family: "Font Awesome 5"
                            color: "white"
                            font.pixelSize: 16
                            width: parent.width
                            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                        }
                    }
                }

            }
        }
    }
    ListView
    {
        id: messagesListView
        currentIndex: 0
        anchors.fill: parent
        highlightFollowsCurrentItem: false
        model: MessagesModel
        {
            id: messagesList
        }
        delegate: messagesDelegate
        spacing: 1
        focus: false
     }
}
