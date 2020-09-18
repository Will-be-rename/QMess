#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Windows/windowcontroller.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    WindowController windowController;
    windowController.start();
    return app.exec();
}
