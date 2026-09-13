cmake_minimum_required(VERSION 3.16)

project(state LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_AUTOMOC ON)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_add_executable(state
    main.cpp
  context/ServerContext.cpp
    context/ServerContext.h
    state/ServerState.h
    state/DownState.cpp
    state/DownState.h
    state/AvailableState.cpp
    state/AvailableState.h
    state/BusyState.cpp
    state/BusyState.h
    ui/ServerDropArea.cpp
    ui/ServerDropArea.h
)

target_link_libraries(state PRIVATE
    Qt6::Widgets
)
add_custom_command(
    TARGET state POST_BUILD
    COMMAND sed -i 's/ -mno-direct-extern-access//g' ${CMAKE_BINARY_DIR}/compile_commands.json
    COMMENT "-mno-direct-extern-access removed"
)
