project(Game)
option(BUILD_SHARED_LIBS "Build shared libraries" ON)

# Install libraries
include(3P-libs/SFML/SFML.cmake)

set(TESTABLE_FILES
        src/Core/EventsHandling/ListenersEmitters.h
        src/Core/EventsHandling/BaseClasses.h
        src/Simulation/Simulation.h
        src/Simulation/Simulation.cpp
        src/Core/Types.h
        src/Core/Storage/RootConfig.h
)

set(SOURCE_FILES
        ${TESTABLE_FILES}
        src/main.cpp
        src/Core/Application/Application.cpp
        src/Core/Application/Application.h
        src/UI/Elements/Button.cpp
        src/UI/Menus/BaseMenu.cpp
        src/UI/Menus/BaseMenu.h
        src/Core/MenuManager/MenuManager.cpp
        src/Core/MenuManager/MenuManager.h
        src/UI/Menus/MainMenu.cpp
        src/UI/Menus/MainMenu.h
        src/UI/Menus/GameplayMenu.cpp
        src/UI/Menus/GameplayMenu.h
        src/UI/Menus/PauseMenu.cpp
        src/UI/Menus/PauseMenu.h
        src/UI/Menus/EndGameMenu.cpp
        src/UI/Menus/EndGameMenu.h
        src/Utility/Updatable.h
        src/Utility/Singleton.h
        src/Utility/Singleton.h
        src/Core/Application/LowLevelApplication.cpp
        src/Core/Application/LowLevelApplication.h
        src/Utility/Logger/Logger.cpp
        src/Utility/Logger/Logger.h
        src/Core/Storage/Config/GeneralConfig.h
        src/Core/Storage/Config/ConfigSimulation.h
        src/Core/Storage/Localization/GeneralLocalization.h
        src/Utility/Serialization/Serializable.h
        src/Core/Application/ApplicationShortcuts.cpp
        src/Core/Application/ApplicationShortcuts.h
        src/Utility/SystemRelated/SystemRelated.cpp
        src/Utility/SystemRelated/SystemRelated.h
        src/Core/Storage/Config/ConfigWindow.h
        src/Core/Storage/Config/ConfigFile.h
        src/Core/Storage/Config/ConfigLogs.h
        src/Core/UserJsonConversions.h
        src/Core/Storage/Localization/LocalizationLogLevel.h
        src/Core/Storage/Localization/LocalizationFileOperations.h
        src/Utility/Serialization/StdJsonConverters.h
        src/Core/Storage/StorageRoot.cpp
        src/Core/Storage/StorageRoot.h
        src/Core/Storage/RootLocalization.h
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
