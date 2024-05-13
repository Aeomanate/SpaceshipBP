cmake_minimum_required(VERSION 3.24)
project(SpaceShipBP)

# CMake Options
enable_testing()
cmake_policy(SET CMP0135 NEW)

# Install global-using libs
include(${CMAKE_SOURCE_DIR}/3P-libs/RapidJSON/rapidjson.cmake)

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
    message("Making static build...")

    set(BUILD_TAG "static")

    set(SFML_STATIC  ON)

    if(MSVC)
        add_compile_options(/Ox)
    else ()
        add_compile_options(-O3)
    endif ()

    set(BUILD_SHARED_LIBS OFF)
    link_libraries("-static")
    set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_DIR}-${OUTPUT_COMPILER}-debug-${BUILD_TAG}/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_DIR}-${OUTPUT_COMPILER}-release-${BUILD_TAG}/")

add_compile_definitions(_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS)
add_compile_definitions(PROGRAM_WIDE_DEFAULT_JSON_CONVERSION_TYPE=GameJsonConversions)

# Include project.
add_subdirectory(Game)

#Include tests
add_subdirectory(GameTests)
