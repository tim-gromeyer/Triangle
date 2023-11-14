cmake_minimum_required(VERSION 3.21.1)

project(TriangleApp LANGUAGES CXX)

set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 6.2 REQUIRED COMPONENTS Core Gui Qml Quick)

if (Qt6_VERSION VERSION_GREATER_EQUAL 6.3)
    qt_standard_project_setup()
endif()

qt_add_executable(TriangleApp
    src/main.cpp
    src/triangle.cpp    src/triangle.h
    ui/qml.qrc
    ressources/ressources.qrc
)

target_link_libraries(TriangleApp PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
)

set_target_properties(TriangleApp PROPERTIES
    QT_ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_SOURCE_DIR}/android"
)

include(GNUInstallDirs)
install(TARGETS TriangleApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
