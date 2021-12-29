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
  )

set(FORMS
  MainWindow.ui
  ConfigSetupDialog.ui
  EthernetSettingsPage.ui
  Ipv4SettingsPage.ui
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
)

set(RESOURCES
  application.qrc
)

# Custom target to force header-only display in CMake-aware IDEs
add_custom_target(ide-headers SOURCES ${HEADERS})

add_executable(qt-sandbox qt-sandbox.cpp ${FORMS} ${RESOURCES} ${SOURCES})
target_link_libraries(qt-sandbox PRIVATE Qt5::Widgets)
