project(Game)
option(BUILD_SHARED_LIBS "Build shared libraries" ON)

# Install libraries
include(3P-libs/SFML/SFML.cmake)
include(3P-libs/RapidJSON/rapidjson.cmake)

set(TESTABLE_FILES
        src/Utility/EventsHandling/ListenersEmitters.h
        src/Utility/EventsHandling/BaseClasses.h
        src/Simulation/Simulation.h
        src/Simulation/Simulation.cpp
        src/Core/Types.h
        src/Core/Config.h
        src/Core/Config.cpp
)

set(SOURCE_FILES
        ${TESTABLE_FILES}
        src/main.cpp
        src/Core/Application/Application.cpp
        src/Core/Application/Application.h
        src/UI/Button.cpp
        src/UI/BaseMenu.cpp
        src/UI/BaseMenu.h
        src/Utility/MenuManager/MenuManager.cpp
        src/Utility/MenuManager/MenuManager.h
        src/UI/MainMenu.cpp
        src/UI/MainMenu.h
        src/Utility/MenuManager/TemplateSpecializes.h
        src/Core/Application/WindowHandling.cpp
        src/Core/Application/ListenerHandling.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

set(TestsLib ${PROJECT_NAME}TestsSource)
add_library(${TestsLib} STATIC ${TESTABLE_FILES})

foreach (TARGET ${PROJECT_NAME} ${TestsLib})
    add_dependencies(${TARGET} RapidJSON)
    target_link_libraries(${TARGET} PUBLIC sfml-system sfml-window sfml-graphics)
    target_include_directories(${TARGET} PUBLIC "src")
endforeach ()

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

add_custom_target(Run_GameTests
        COMMAND GameTests
        COMMENT "Running GameTests...")

add_dependencies(${PROJECT_NAME} Run_GameTests)
