#-------------------------------------------------
#
# Project created by QtCreator 2019-06-24T13:11:24
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DesktopClient
TEMPLATE = app
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES -= QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        cachedmessagehistory.cpp \
        loginwindow.cpp \
        main.cpp \
        chatwindow.cpp \
        eventmessageprocessor.cpp \
        datastorage.cpp \
        windowcontroller.cpp

HEADERS += \
        cachedmessagehistory.h \
        chatwindow.h \
        eventmessageprocessor.h \
        datastorage.h \
        loginwindow.h \
        windowcontroller.h

FORMS += \
        chatwindow.ui \
        loginwindow.ui

RESOURCES += \
    images/imagesresource.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-libModel/release/ -llibModel
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-libModel/debug/ -llibModel
else:unix: LIBS += -L$$PWD/../build-libModel/ -llibModel

INCLUDEPATH += $$PWD/../libModel

INCLUDEPATH += $$PWD/../build-libModel/release
DEPENDPATH += $$PWD/../build-libModel/release

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-libModel/release/liblibModel.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-libModel/debug/liblibModel.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-libModel/release/libModel.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-libModel/debug/libModel.lib
else:unix: PRE_TARGETDEPS += $$PWD/../build-libModel/liblibModel.a

DISTFILES += \
    todo
