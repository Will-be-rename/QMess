cmake_minimum_required(VERSION 3.10)

project(Client VERSION 1.0)

find_package(Qt5 REQUIRED Core Widgets Gui Qml Quick Network)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(sources

        src/Processors/datastorage.cpp
        src/Processors/eventmessageprocessor.cpp
        src/ViewModels/messagesmodel.cpp
        src/ViewModels/messageview.cpp
        src/ViewModels/user.cpp
        src/ViewModels/usermodel.cpp
        src/Windows/chatwindow.cpp
        src/Windows/loginwindow.cpp
        src/Windows/windowcontroller.cpp
    )

set(headers

        src/Processors/datastorage.h
        src/Processors/eventmessageprocessor.h
        src/ViewModels/messagesmodel.h
        src/ViewModels/messageview.h
        src/ViewModels/user.h
        src/ViewModels/usermodel.h
        src/Windows/chatwindow.h
        src/Windows/loginwindow.h
        src/Windows/windowcontroller.h
    )

set(resourses

        src/qml.qrc)

add_library(clientLib STATIC

    ${sources}
    ${headers}
    ${resourses})

target_link_libraries(clientLib
    libModel
    Qt5::Core
    Qt5::Network
    Qt5::Gui
    Qt5::Qml
    Qt5::Quick
    Qt5::Widgets)

target_include_directories(clientLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

add_executable(Client src/main.cpp)
target_link_libraries(Client clientLib)
					

