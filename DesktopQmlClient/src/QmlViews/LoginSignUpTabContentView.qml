import QtQuick 2.12

Rectangle {

    id: root

    width: parent.width
    height:parent.height

    signal signUpClicked()

    LoginInputField
    {
        id: usernameField
        placeholder: "Username"

        anchors.top: root.top
        anchors.topMargin: 110

        anchors.left: root.left
        anchors.leftMargin: 131

        iconSource: "../Resources/Images/login_username_logo.png"
    }

    LoginInputField
    {
        id: emailField
        placeholder: "Email"

        anchors.top: usernameField.bottom
        anchors.topMargin: 100

        inputMethodHints: Qt.ImhEmailCharactersOnly

        anchors.left: usernameField.left

        iconSource: "../Resources/Images/login_email_logo.png"
    }

    LoginInputField
    {
        id: phoneField
        placeholder: "Phone"

        anchors.top: emailField.bottom
        anchors.topMargin: 100

        inputMethodHints: Qt.ImhDialableCharactersOnly

        anchors.left: usernameField.left

        iconSource: "../Resources/Images/login_phone_logo.png"
    }

    LoginInputField
    {
        id: passwordField

        placeholder: "Password"

        underlineButtonText: "Please use 6-20 characters (A-Z, a-z, 0-9 only)"

        anchors.top: phoneField.bottom
        anchors.topMargin: 100

        anchors.left: usernameField.left

        echoMode: TextInput.Password

        iconSource: "../Resources/Images/login_pwd_logo_2.png"
    }

    LoginConfirmButton
    {
        id: confirmButton

        anchors.top: passwordField.bottom
        anchors.topMargin: 30
        anchors.horizontalCenter: passwordField.horizontalCenter

        text: qsTr("Sign Up")

        onClicked:
        {
            root.signUpClicked();
        }

    }

}
