cmake_minimum_required(VERSION 3.20)

project(weet VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.11 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(weet
    src/main.cpp
    src/device.cpp
    src/oscillator.cpp
    src/window.cpp
    src/audio.cpp
)

qt_add_qml_module(weet
    URI Weet
    VERSION 1.0
    QML_FILES
        Main.qml
        WeetButton.qml
        Knob.qml
)

target_include_directories(weet PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party
)

target_link_libraries(weet PRIVATE
    Qt6::Quick
)

set_target_properties(weet PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
)