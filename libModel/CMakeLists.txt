cmake_minimum_required(VERSION 3.10)

project(libModel VERSION 1.0)

find_package(Qt5Core)
find_package(Qt5Network)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(sources

    src/models.cpp
    src/tcpdataprovider.cpp)

set(headers

    src/models.h
    src/tcpdataprovider.h
    src/tcpdefines.h)

add_library(libModel STATIC

    ${headers}
    ${sources})

target_link_libraries(libModel
        Qt5::Core
        Qt5::Network)

target_include_directories(libModel PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(libModel INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")

