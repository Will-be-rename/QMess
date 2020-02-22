QT += quick

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ViewModels/messagesmodel.cpp \
        ViewModels/user.cpp \
        ViewModels/usermodel.cpp \
        main.cpp \

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
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

HEADERS += \
    ViewModels/messagesmodel.h \
    ViewModels/user.h \
    ViewModels/usermodel.h \

