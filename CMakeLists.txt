cmake_minimum_required(VERSION 3.16)

project(controller VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick DBus)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appcontroller
    main.cpp
)

target_sources(appcontroller
  PRIVATE
    sender1.h sender1.cpp
)

qt_add_qml_module(appcontroller
    URI controller
    VERSION 1.0
    QML_FILES
        Main.qml
)

set_target_properties(appcontroller PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appcontroller
    PRIVATE Qt6::Quick Qt6::DBus
)

include(GNUInstallDirs)
install(TARGETS appcontroller
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
