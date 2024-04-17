project(GameTests)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

set(SOURCE_FILES
        src/Utility.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Install libraries
include(3P-libs/GTest/googletest.cmake)
add_dependencies(${PROJECT_NAME} RapidJSON)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
        GTest::gtest_main
        GameTestsSource
)

target_include_directories(${PROJECT_NAME} PUBLIC GameTestsSource)

