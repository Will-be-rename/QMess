#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "ViewModels/usermodel.h"
#include "ViewModels/messagesmodel.h"
#include "Windows/chatwindow.h"
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    UserModel::registerMe("Users");
    MessagesModel::registerMe("Messages");
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    ChatWindow w;
    return app.exec();
}
