cmake_minimum_required(VERSION 3.11)
project(SpaceShipBP)

# Compiler settings
if (MSVC_VERSION GREATER_EQUAL "1900")
    include(CheckCXXCompilerFlag)
    CHECK_CXX_COMPILER_FLAG("/std:c++20" _cpp_standard_flag_supported)
    if (_cpp_standard_flag_supported)
        add_compile_options("/std:c++20")
    endif()
endif()

option(BUILD_SHARED_LIBS "Build shared libraries" ON)

# Install libraries
include(FetchContent)

## SFML
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

## RapidJSON
include("SpaceShipBP/libs/RapidJSON/rapidjson.cmake")
include_directories(${RAPIDJSON_INCLUDE_DIR})

# Include project.
add_subdirectory ("SpaceShipBP")
