project(QMess)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# libModel
add_subdirectory("libModel")
# Server
add_subdirectory("Server")
# DesktopQmlClient
add_subdirectory("DesktopQmlClient")
