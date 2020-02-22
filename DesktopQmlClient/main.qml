import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import "QmlViews/"

Window {
    id: mainWindow

    visible: true
    width: 1920
    height: 1080
    title: qsTr("MainWindow")
    UserListView
    {
        id: _listRectangle
    }
    MessagesView
    {
        anchors.left: _listRectangle.right
    }
}
