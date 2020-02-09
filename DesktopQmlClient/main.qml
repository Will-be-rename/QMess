import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("QMess")

    GridLayout{
        Rectangle{
            anchors.centerIn : parent
            color: "silver"
            width: 50
            height: 20
            TextArea {
                id: name
            }
        }
    }

}
