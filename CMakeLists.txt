cmake_minimum_required(VERSION 3.20)

project(weet LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

add_executable(weet
    src/main.cpp
    src/device.cpp
    src/oscillator.cpp
    # src/window.cpp
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