cmake_minimum_required(VERSION 3.7)

project(qt-sandbox)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(HEADERS
  MainWindow.h
  ConfigSetupDialog.h
  ConfigSetupSettings.h
  Configuration.h
  DnsDataModel.h
  EthernetSettings.h
  Ipv4Settings.h
  InterfaceSettings.h
  EthernetSettingsPage.h
  Ipv4SettingsPage.h
  DnsItemDelegate.h
  ConfigTreeItem.h
  ConfigTreeModel.h
  ConfigTreeRootItem.h
  ConfigPage.h
  ConfigSection.h
  ExamplePage.h
  AnotherPage.h
  Form.h
  )

set(FORMS
  MainWindow.ui
  ConfigSetupDialog.ui
  EthernetSettingsPage.ui
  Ipv4SettingsPage.ui
  ExamplePage.ui
  AnotherPage.ui
  Form.ui
  )

set(SOURCES
  MainWindow.cpp
  ConfigSetupDialog.cpp
  EthernetSettingsPage.cpp
  Ipv4SettingsPage.cpp
  DnsDataModel.cpp
  DnsItemDelegate.cpp
  ConfigTreeItem.cpp
  ConfigTreeModel.cpp
  ConfigTreeRootItem.cpp
  ConfigPage.cpp
  ConfigSection.cpp
  ExamplePage.cpp
  AnotherPage.cpp
  Form.cpp
)

set(RESOURCES
  application.qrc
)

# Custom target to force header-only display in CMake-aware IDEs
add_custom_target(ide-headers SOURCES ${HEADERS})

add_library(sandbox ${FORMS} ${RESOURCES} ${SOURCES})
target_link_libraries(sandbox PUBLIC Qt5::Widgets)

add_executable(qt-sandbox qt-sandbox.cpp)
target_link_libraries(qt-sandbox PRIVATE sandbox)

add_executable(test test.cpp)
target_link_libraries(test PRIVATE sandbox)
