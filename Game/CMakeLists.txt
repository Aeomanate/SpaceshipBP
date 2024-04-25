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
        src/Core/GameLayers/MenuLayer.cpp
        src/Core/GameLayers/MenuLayer.h
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
        src/Core/Storage/Config/ConfigPath.h
        src/Core/Storage/GameJsonConversions.h
        src/Core/Storage/Localization/LocLogLevel.h
        src/Core/Storage/Localization/LocFileOperations.h
        src/Utility/Serialization/ImplStdJsonConverters.h
        src/Core/Storage/StorageRoot.cpp
        src/Core/Storage/StorageRoot.h
        src/Core/Storage/RootLocalization.h
        src/Utility/Serialization/ImplMacroses.h
        src/Utility/Serialization/Serializable.h
        src/Simulation/ECS/System.cpp
        src/Simulation/ECS/System.h
        src/Simulation/ECS/Entity.cpp
        src/Simulation/ECS/Entity.h
        src/Simulation/ECS/Component.cpp
        src/Simulation/ECS/Component.h
        src/Simulation/ECS/BasicFeatures/Movable/CPosition.h
        src/Simulation/ECS/BasicFeatures/Movable/CSpeed.h
        src/Simulation/ECS/BasicFeatures/Visual/CSprite.h
        src/Simulation/ECS/BasicFeatures/Visual/SSpriteAnimator.cpp
        src/Simulation/ECS/BasicFeatures/Visual/SSpriteAnimator.h
        src/Simulation/ECS/BasicFeatures/Movable/EntityMover.cpp
        src/Simulation/ECS/BasicFeatures/Movable/SEntityMover.h
        src/Simulation/ECS/BasicFeatures/Visual/SEntityDrawer.cpp
        src/Simulation/ECS/BasicFeatures/Visual/SEntityDrawer.h
        src/Simulation/ECS/BasicFeatures/Movable/CMass.h
        src/Simulation/ECS/BasicFeatures/Movable/CAppliedForces.h
        src/Simulation/ECS/BasicFeatures/CollisionDetection/SCollisionDetector.cpp
        src/Simulation/ECS/BasicFeatures/CollisionDetection/SCollisionDetector.h
        src/Simulation/Entities/EPlayer.h
        src/Simulation/Entities/EAsteroid.h
        src/Simulation/Entities/ETimer.h
        src/Simulation/Features/Shooting/EProjectile.h
        src/Utility/Visual/FrameByFrame.h
        src/Utility/Visual/FrameByFrame.cpp
        src/Core/Storage/Config/ConfigTextures.h
        src/Core/Storage/Config/ConfigTexture.h
        src/Utility/Math/Vectors/Vectors.h
        src/Utility/Math/Vectors/Vectors.h
        src/Utility/Math/Vectors/Vectors.cpp
        src/Utility/Math/Random/Random.cpp
        src/Core/Storage/Localization/LocApplication.h
        src/Utility/Visual/TextureProvider.cpp
        src/Utility/Visual/TextureProvider.h
        src/Simulation/Levels/Level.cpp
        src/Simulation/Levels/Level.h
        src/Simulation/Entities/EBackground.h
        src/Simulation/Levels/LevelProvider.cpp
        src/Simulation/Levels/LevelProvider.h
        src/Core/Storage/Config/ConfigLevel.h
        src/Core/Storage/Config/ConfigLevels.h
        src/Core/Storage/Localization/LocSimulation.h
        src/Simulation/Features/DangerZone/EDangerZone.h
        src/Simulation/Features/DangerZone/CDangerZoneParams.h
        src/Simulation/Features/DangerZone/CDangerZoneStat.h
        src/Simulation/Features/DangerZone/SDangerZoneTracker.cpp
        src/Simulation/Features/DangerZone/SDangerZoneTracker.h
        src/Simulation/Features/Score/CPlayerScore.h
        src/Simulation/Features/Score/SScoreTracker.cpp
        src/Simulation/Features/Score/SScoreTracker.h
        src/Simulation/Features/DangerZone/SDangerZoneAsteroidSpawner.cpp
        src/Simulation/Features/DangerZone/SDangerZoneAsteroidSpawner.h
        src/Simulation/Features/Shooting/SHitHandler.cpp
        src/Simulation/Features/Shooting/SHitHandler.h
        src/Simulation/Features/Shooting/CHitConfirmed.h
        src/Simulation/ECS/BasicFeatures/LifetimeControl/CToSpawnQueue.h
        src/Simulation/ECS/BasicFeatures/LifetimeControl/CToDespawnMark.h
        src/Simulation/ECS/BasicFeatures/LifetimeControl/SSpawner.cpp
        src/Simulation/ECS/BasicFeatures/LifetimeControl/SSpawner.h
        src/Simulation/ECS/BasicFeatures/LifetimeControl/SDespawner.cpp
        src/Simulation/ECS/BasicFeatures/LifetimeControl/SDespawner.h
        src/Simulation/ECS/BasicFeatures/LifetimeControl/CVisualAttenuation.h
        src/Simulation/ECS/BasicFeatures/LifetimeControl/SVisualAttenuationController.cpp
        src/Simulation/ECS/BasicFeatures/LifetimeControl/SVisualAttenuationController.h
        src/Simulation/ECS/BasicFeatures/LifetimeControl/ESpawnerContainer.h
        src/Simulation/ECS/BasicFeatures/PlayerControllable/CPlayerControllableTag.h
        src/Simulation/ECS/BasicFeatures/PlayerControllable/CInputQueue.h
        src/Simulation/ECS/BasicFeatures/PlayerControllable/SInputInjector.cpp
        src/Simulation/ECS/BasicFeatures/PlayerControllable/SInputInjector.h
        src/Simulation/ECS/BasicFeatures/PlayerControllable/EInputContainer.h
        src/Simulation/ECS/BasicFeatures/PlayerControllable/SInputApplier.cpp
        src/Simulation/ECS/BasicFeatures/PlayerControllable/SInputApplier.h
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
