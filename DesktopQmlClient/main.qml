import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import "QmlViews/"

ApplicationWindow
{
    id: loginWindow
    width: 754
    height: 858

    visible: true
    color: "#00000000"

    flags: Qt.Window | Qt.FramelessWindowHint

    background: Rectangle {
        anchors.fill: parent
        radius: 80
    }

    LoginView {
        id: loginView
        anchors.fill: parent

        onMinimizeWindow:
        {
            loginWindow.showMinimized()
        }

        onCloseWindow:
        {
            loginWindow.close()
        }

        onWindowPositionChanged:
        {
            loginWindow.x += position.x;
            loginWindow.y += position.y;
        }

        onSignInRequest:
        {
            /* TODO: implemented sign in request */
            chatWindow.show();
            loginWindow.hide();
        }

        onSignUpRequest:
        {
            /* TODO: implement registration request */
            chatWindow.show();
            loginWindow.hide();
        }
    }
    Window {
        id: chatWindow
        width: 1920
        height: 1080
        title: qsTr("ChatWindow")

        ChatWindowView { }
    }
}
