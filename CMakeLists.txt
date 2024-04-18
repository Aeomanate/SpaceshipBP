cmake_minimum_required(VERSION 3.24)
project(SpaceShipBP)

# CMake Options
enable_testing()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_SOURCE_DIR}/Game/bin-debug")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/Game/bin-release")

cmake_policy(SET CMP0135 NEW)

# Install global-using libs
include(${CMAKE_SOURCE_DIR}/3P-libs/RapidJSON/rapidjson.cmake)

# Compiler settings
set(CMAKE_CXX_STANDARD 20)

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -fconcepts-diagnostics-depth=10)
endif()

add_compile_definitions(_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS)
add_compile_definitions(PROGRAM_WIDE_DEFAULT_JSON_CONVERSION_TYPE=GameJsonConversions)

# Include project.
add_subdirectory(Game)

#Include tests
add_subdirectory(GameTests)
