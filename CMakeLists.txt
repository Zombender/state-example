cmake_minimum_required(VERSION 3.16)

project(state LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_add_executable(state
    main.cpp
    view/designer.h
)

target_link_libraries(state PRIVATE
    Qt6::Widgets
)
