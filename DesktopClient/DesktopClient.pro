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
        main.cpp \
        chatwindow.cpp \
        eventmessageprocessor.cpp \
        datastorage.cpp

HEADERS += \
        chatwindow.h \
        eventmessageprocessor.h \
        datastorage.h

FORMS += \
        chatwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-libModel-Desktop_Qt_5_12_2_MSVC2017_64bit-Release/release/ -llibModel
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-libModel-Desktop_Qt_5_12_2_MSVC2017_64bit-Debug/debug/ -llibModel
else:unix: LIBS += -L$$PWD/../build-libModel-Desktop_Qt_5_12_2_MSVC2017_64bit-Release/ -llibModel

INCLUDEPATH += $$PWD/../libModel

INCLUDEPATH += $$PWD/../build-libModel-Desktop_Qt_5_12_2_MSVC2017_64bit-Release/release
DEPENDPATH += $$PWD/../build-libModel-Desktop_Qt_5_12_2_MSVC2017_64bit-Release/release

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-libModel-Desktop_Qt_5_12_2_MSVC2017_64bit-Release/release/liblibModel.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-libModel-Desktop_Qt_5_12_2_MSVC2017_64bit-Debug/debug/liblibModel.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-libModel-Desktop_Qt_5_12_2_MSVC2017_64bit-Release/release/libModel.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-libModel-Desktop_Qt_5_12_2_MSVC2017_64bit-Debug/debug/libModel.lib
else:unix: PRE_TARGETDEPS += $$PWD/../build-libModel-Desktop_Qt_5_12_2_MSVC2017_64bit-Release/liblibModel.a

DISTFILES += \
    todo
