cmake_minimum_required(VERSION 3.2)
project(inf-vs-zombies C)

# Put the executable file in the bin folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Export compile commands for Zed's language server
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include FetchContent to make raylib work
include(FetchContent)

# Prevents unnecessary downloads
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE)

# Makes FetchContent able to reach Raylib
FetchContent_Declare(
    raylib
    GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
    GIT_TAG "master"
    GIT_PROGRESS TRUE
)

# Makes Raylib available
FetchContent_MakeAvailable(raylib)

# Add the include directory to the compiler's search path
include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(inf-vs-zombies
    src/main.c
    src/plants.c
    src/zombies.c
    src/map.c
    src/buttons.c
    src/plantsbar.c
    src/table.c
    src/clock.c
)

target_link_libraries(inf-vs-zombies PRIVATE raylib)
