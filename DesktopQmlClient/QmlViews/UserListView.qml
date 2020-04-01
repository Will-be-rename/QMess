import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle
{
    id: listRectangle

    color: "#94918E"

    layer.enabled: true
    Component
    {
        id: userDelegate

        Row
        {
            leftPadding: 8
            rightPadding: 8
            bottomPadding: 8

            ItemDelegate
            {
                    width: listRectangle.width - 16
                    height: listRectangle.height * 0.05
                    background:
                        Rectangle
                        {
                            id: rowRectangle
                            color: "#b8b8b8"
                            anchors.fill: parent
                            radius: width * 0.5
                            opacity: 0.19
                            MouseArea
                            {
                                id: mouse

                                anchors.fill: parent
                                hoverEnabled: true

                                onClicked:
                                {
                                    userListView.currentIndex = index
                                }
                                onEntered:
                                {
                                    rowRectangle.opacity = 0.98
                                }
                                onExited:
                                {
                                    rowRectangle.opacity = 0.19
                                }


                            }
                        }

                    contentItem :
                    Item
                    {
                        anchors.fill: parent
                        Rectangle // user cyrcle
                        {
                             anchors.leftMargin: 5
                             anchors.left: parent.left
                             anchors.bottomMargin: 5
                             anchors.bottom: parent.bottom
                             anchors.topMargin: 5
                             anchors.top: parent.top
                             width: listRectangle.height * 0.05  - 10
                             height: listRectangle.height * 0.05 - 10
                             color: "white"
                             radius: width*0.5
                        }
                        Rectangle // online cyrcle
                        {
                             anchors.leftMargin: 5 + listRectangle.height * 0.05 - 10
                             anchors.left: parent.left
                             anchors.topMargin: 5
                             anchors.top: parent.top
                             width: listRectangle.height * 0.02  - 10
                             height: listRectangle.height * 0.02 - 10
                             color: online ? "green" : "grey"
                             radius: width*0.5
                        }
                        Rectangle // incomming messages cyrcle
                        {
                             anchors.rightMargin: 5 + listRectangle.height * 0.05 - 10
                             anchors.right: parent.right
                             anchors.topMargin: 16
                             anchors.top: parent.top
                             height: listRectangle.height * 0.03 - 10
                             width: height * 2
                             color: "grey"
                             radius: width*0.5
                             visible: incommingMessages == "0" ? false : true
                             Text
                             {
                                anchors.centerIn : parent
                                text: incommingMessages
                                font.family: "Font Awesome 5"
                                font.pixelSize: 16
                             }
                        }
                        Text
                        {
                            id: rowText
                            leftPadding: 75
                            rightPadding: 310
                            topPadding:18
                            bottomPadding:22

                            anchors.centerIn: parent.Center
                            text: name
                            font.family: "Font Awesome 5"
                            color: "white"
                            font.pixelSize: 18
                        }
                    }
                }
        }
    }

    ListView
    {
        id: userListView
        currentIndex: 0
        anchors.fill: parent
        highlightFollowsCurrentItem: false
        model: userModel
        delegate: userDelegate
        spacing: 1
        focus: true
        highlight:
            Row
            {
                    leftPadding: 8
                    Rectangle
                    {
                        width: listRectangle.width - 16
                        height: listRectangle.height * 0.05
                        color: "lightblue"
                        radius: width * 0.5
                        y:  userListView.currentItem.y
                    }
            }
        onCurrentItemChanged:
        {
            userModel.selectionChanged(userListView.currentIndex);
        }
    }


}

