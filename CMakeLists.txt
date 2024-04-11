cmake_minimum_required (VERSION 3.8)
project ("SpaceShipBP")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# Compiler settings
if (MSVC_VERSION GREATER_EQUAL "1900")
    include(CheckCXXCompilerFlag)
    CHECK_CXX_COMPILER_FLAG("/std:c++20" _cpp_standard_flag_supported)
    if (_cpp_standard_flag_supported)
        add_compile_options("/std:c++20")
    endif()
endif()


# Include project.
add_subdirectory ("SpaceShipBP")

# Install SFML
option(BUILD_SHARED_LIBS "Build shared libraries" ON)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)