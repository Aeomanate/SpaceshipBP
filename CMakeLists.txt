cmake_minimum_required(VERSION 3.24)
cmake_policy(SET CMP0135 NEW)

enable_testing()
project(SpaceShipBP)

# Compiler settings
set(CMAKE_CXX_STANDARD 20)

set(OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Game/bin")
set(BUILD_TAG "shared")
set(BUILD_SHARED_LIBS ON)

if(MSVC)
    set(OUTPUT_COMPILER "MSVS")
    add_compile_options(/W4)
else()
    set(OUTPUT_COMPILER "MinGW")
    add_compile_options(-Wall -Wextra -Wpedantic -fconcepts-diagnostics-depth=10)
endif()

if(CMAKE_BUILD_TYPE MATCHES Release)
    if(MSVC)
        add_compile_options(/Ox)
        set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDLL")
    else ()
        set(BUILD_TAG "static")
        add_compile_options(-O3)
        link_libraries("-static")
        set(BUILD_SHARED_LIBS OFF)
    endif ()
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_DIR}-${OUTPUT_COMPILER}-debug-${BUILD_TAG}/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_DIR}-${OUTPUT_COMPILER}-release-${BUILD_TAG}/")

add_compile_definitions(_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS)
add_compile_definitions(PROGRAM_WIDE_DEFAULT_JSON_CONVERSION_TYPE=GameJsonConversions)

# Install global-using libs
include(${CMAKE_SOURCE_DIR}/3P-libs/RapidJSON/rapidjson.cmake)

# Include project.
add_subdirectory(Game)

#Include tests
add_subdirectory(GameTests)
