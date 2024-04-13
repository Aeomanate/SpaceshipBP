cmake_minimum_required(VERSION 3.24)
project(SpaceShipBP)
enable_testing()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_SOURCE_DIR}/Game/bin-debug")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/Game/bin-release")

# CMake Options
cmake_policy(SET CMP0135 NEW)

# Compiler settings
if (MSVC_VERSION GREATER_EQUAL "1900")
    include(CheckCXXCompilerFlag)
    CHECK_CXX_COMPILER_FLAG("/std:c++17" _cpp_standard_flag_supported)
    if (_cpp_standard_flag_supported)
        add_compile_options("/std:c++17")
    endif()
endif()

# Include project.
add_subdirectory(Game)

#Include tests
add_subdirectory(GameTests)
