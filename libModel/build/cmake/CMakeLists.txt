cmake_minimum_required(VERSION 3.0)
project(lib-model)				

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_BINARY_DIR  "../bin/")
set(SOURCE_LIB     
	../models.cpp
    	../tcpdataprovider.cpp)		

find_package(Qt5 COMPONENTS Core)
find_package(Qt5 COMPONENTS Network)

add_library(lib-model STATIC ${SOURCE_LIB})
qt5_use_modules(lib-model Network)
