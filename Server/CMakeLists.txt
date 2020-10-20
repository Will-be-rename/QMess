cmake_minimum_required(VERSION 3.10)

project(Server VERSION 1.0)

find_package(Qt5Core)
find_package(Qt5Network)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(commandsSrc
    src/Commands/ICommand.h
    src/Commands/IWorker.h
    src/Commands/SyncWorker.cpp
    src/Commands/SyncWorker.h
    src/Commands/SetupUserCommand.cpp
    src/Commands/SetupUserCommand.h
    src/Commands/CommandAdapter.cpp
    src/Commands/CommandAdapter.h)

set(dataprovidersSrc

    src/DataProviders/idataprovider.cpp
    src/DataProviders/idataprovider.h
    src/DataProviders/mockdataprovider.cpp
    src/DataProviders/mockdataprovider.h
    )

set(handlersSrc

    src/Handlers/eventhandler.cpp
    src/Handlers/eventhandler.h
    )

set(runableSrc

    src/QRunable/connectionhandler.cpp
    src/QRunable/connectionhandler.h
    src/QRunable/disconnectionhandler.cpp
    src/QRunable/disconnectionhandler.h
    src/QRunable/runnabledirector.cpp
    src/QRunable/runnabledirector.h
    )

set(serverSrc

    src/serverrunner.cpp
    src/serverrunner.h
    src/sessionclient.cpp
    src/sessionclient.h
    )

add_library(serverLib STATIC

    ${commandsSrc}
    ${serverSrc}
    ${dataprovidersSrc}
    ${handlersSrc}
    ${runableSrc})

target_link_libraries(serverLib
    libModel
    Qt5::Core
    Qt5::Network)
target_include_directories(serverLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
add_executable(Server src/main.cpp)
target_link_libraries(Server serverLib)
					

