cmake_minimum_required(VERSION 3.7)

project(qt-sandbox)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(FORMS
)

set(SOURCES
  MainWindow.cpp
)

set(RESOURCES
  application.qrc
)

add_executable(qt-sandbox qt-sandbox.cpp ${FORMS} ${RESOURCES} ${SOURCES})
target_link_libraries(qt-sandbox PRIVATE Qt5::Widgets)
