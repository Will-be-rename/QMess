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

//    LoginView { anchors.centerIn: parent }
    ChatWindowView { }
}
