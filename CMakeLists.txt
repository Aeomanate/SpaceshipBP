cmake_minimum_required(VERSION 3.24)
project(SpaceShipBP)
enable_testing()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_SOURCE_DIR}/Game/bin-debug")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/Game/bin-release")

# CMake Options
cmake_policy(SET CMP0135 NEW)


# Compiler settings
set(CMAKE_CXX_STANDARD 20)

if(MSVC)
    # warning level 4
    add_compile_options(/W4)
else()
    # additional warnings
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_compile_definitions(_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS)

# Include project.
add_subdirectory(Game)

#Include tests
add_subdirectory(GameTests)
