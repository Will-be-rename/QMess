#include "windowcontroller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WindowController w;
    w.start();

    return a.exec();
}
