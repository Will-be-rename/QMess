import QtQuick 2.12

Rectangle {

    id: root

    width: parent.width
    height:parent.height

    signal signInClicked()

    LoginInputField
    {
        id: usernameField
        placeholder: "Username"

        anchors.top: root.top
        anchors.topMargin: 143

        anchors.left: root.left
        anchors.leftMargin: 131

        iconSource: "../Resources/Images/login_username_logo.png"
    }

    LoginInputField
    {
        id: emailField
        placeholder: "Email"

        anchors.top: usernameField.bottom
        anchors.topMargin: 121

        inputMethodHints: Qt.ImhEmailCharactersOnly

        anchors.left: usernameField.left

        iconSource: "../Resources/Images/login_email_logo.png"
    }

    LoginInputField
    {
        id: passwordField

        placeholder: "Password"

        underlineButtonText: "Forgot password?"

        anchors.top: emailField.bottom
        anchors.topMargin: 121

        anchors.left: usernameField.left

        echoMode: TextInput.Password

        iconSource: "../Resources/Images/login_pwd_logo.png"
    }

    LoginConfirmButton
    {
        id: confirmButton

        anchors.top: passwordField.bottom
        anchors.topMargin: 56
        anchors.horizontalCenter: passwordField.horizontalCenter

        text: qsTr("Sign In")

        onClicked:
        {
            root.signInClicked();
        }
    }
}
