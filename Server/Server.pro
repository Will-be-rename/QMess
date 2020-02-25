QT -= gui
QT += network

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        DataProviders/idataprovider.cpp \
        Handlers/eventhandler.cpp \
        QRunable/connectionhandler.cpp \
        QRunable/disconnectionhandler.cpp \
        main.cpp \
        QRunable/runnabledirector.cpp \
        serverrunner.cpp \
        sessionclient.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
        DataProviders/idataprovider.h \
        Handlers/eventhandler.h \
        QRunable/connectionhandler.h \
        QRunable/disconnectionhandler.h \
        QRunable/runnabledirector.h \
        serverrunner.h \
        sessionclient.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-libModel/release/ -llibModel
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-libModel/debug/ -llibModel
else:unix: LIBS += -L$$PWD/../build-libModel/ -llibModel

INCLUDEPATH += $$PWD/../libModel

INCLUDEPATH += $$PWD/../build-libModel
DEPENDPATH += $$PWD/../build-libModel

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-libModel/release/liblibModel.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-libModel/debug/liblibModel.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-libModel/release/libModel.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-libModel/debug/libModel.lib
else:unix: PRE_TARGETDEPS += $$PWD/../build-libModel/liblibModel.a
