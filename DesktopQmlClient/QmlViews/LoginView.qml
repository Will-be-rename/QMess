import QtQuick 2.12

Rectangle {
    id: root
    width: 754
    height: 858

    color: "#B2AFAF"
    radius: 80

    LoginStatusBarView {
        id: statusBar
        width: 643
        height: 248

        color: parent.color
        anchors.top: parent.top
        anchors.topMargin: 9
        anchors.left: parent.left
        anchors.leftMargin: 51
    }

    LoginSignInTabContentView
    {
        id: signInTabContent

        visible: statusBar.isSignInContentActive

        width : 754
        height: 618

        color:  "#C4C4C4"

        radius: 40

        anchors.bottom: root.bottom
    }

    LoginSignUpTabContentView
    {
        id: signUpTabContent

        visible: !statusBar.isSignInContentActive

        width: 754
        height: 618

        color: "#C4C4C4"

        radius: 40

        anchors.bottom: root.bottom
    }
}
