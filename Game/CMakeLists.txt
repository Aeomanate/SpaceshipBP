project(Game)
option(BUILD_SHARED_LIBS "Build shared libraries" ON)

# Install libraries
include(3P-libs/SFML/SFML.cmake)
include(3P-libs/better-enums/better-enums.cmake)

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
        src/Simulation/ECS/System.h
        src/Simulation/ECS/Entity.h
        src/Simulation/ECS/Component.h
        src/Simulation/ECS/Features/Movable/CPosition.h
        src/Simulation/ECS/Features/Visual/CSceneElement.h
        src/Simulation/ECS/Features/Visual/SSpriteAnimator.cpp
        src/Simulation/ECS/Features/Visual/SSpriteAnimator.h
        src/Simulation/ECS/Features/Movable/EntityMover.cpp
        src/Simulation/ECS/Features/Movable/SEntityMover.h
        src/Simulation/ECS/Features/Visual/SEntityDrawer.cpp
        src/Simulation/ECS/Features/Visual/SEntityDrawer.h
        src/Simulation/ECS/Features/CollisionDetection/SCollisionDetector.cpp
        src/Simulation/ECS/Features/CollisionDetection/SCollisionDetector.h
        src/Simulation/Features/Player/EPlayer.h
        src/Simulation/Features/DangerZone/EAsteroid.h
        src/Simulation/Features/Timer/ETimer.h
        src/Simulation/Features/Shooting/EProjectile.h
        src/Utility/Visual/FrameByFrame.h
        src/Utility/Visual/FrameByFrame.cpp
        src/Core/Storage/Config/ConfigTextures.h
        src/Core/Storage/Config/ConfigTexture.h
        src/Utility/Math/Vectors.h
        src/Utility/Math/Vectors.h
        src/Utility/Math/Vectors.cpp
        src/Utility/Math/Random.cpp
        src/Core/Storage/Localization/LocApplication.h
        src/Utility/Visual/TextureProvider.cpp
        src/Utility/Visual/TexturesCache.h
        src/Simulation/GameLevels/Base/LevelBase.cpp
        src/Simulation/GameLevels/Base/Level.h
        src/Simulation/Features/Background/EBackground.h
        src/Simulation/GameLevels/Base/LevelProvider.cpp
        src/Simulation/GameLevels/Base/LevelProvider.h
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
        src/Simulation/Features/Shooting/SHandlerHit.cpp
        src/Simulation/Features/Shooting/SHandlerHit.h
        src/Simulation/Features/Shooting/CHitConfirmed.h
        src/Simulation/ECS/Features/LifetimeControl/CToSpawnQueue.h
        src/Simulation/ECS/Features/LifetimeControl/CToDespawnMark.h
        src/Simulation/ECS/Features/LifetimeControl/SSpawner.cpp
        src/Simulation/ECS/Features/LifetimeControl/SSpawner.h
        src/Simulation/ECS/Features/LifetimeControl/SDespawner.cpp
        src/Simulation/ECS/Features/LifetimeControl/SDespawner.h
        src/Simulation/ECS/Features/Visual/CVisualAttenuation.h
        src/Simulation/ECS/Features/Visual/SVisualAttenuation.cpp
        src/Simulation/ECS/Features/Visual/SVisualAttenuation.h
        src/Simulation/ECS/Features/LifetimeControl/ESpawnerContainer.h
        src/Simulation/ECS/Features/Input/CPlayerControllableTag.h
        src/Simulation/ECS/Features/Input/CInputMoveDirections.h
        src/Simulation/ECS/Features/Input/SInputInjector.cpp
        src/Simulation/ECS/Features/Input/SInputInjector.h
        src/Simulation/ECS/Features/Levels/CLevelState.h
        src/Simulation/ECS/Features/Levels/ELevelState.h
        src/Simulation/ECS/Features/Levels/SLevelStateForwarder.cpp
        src/Simulation/ECS/Features/Levels/SLevelStateForwarder.h
        src/Simulation/GameLevels/Level1.cpp
        src/Simulation/GameLevels/Level1.h
        src/Simulation/Features/Player/EPlayer.cpp
        src/Simulation/ECS/Features/Input/CInputMouseClicks.h
        src/Simulation/ECS/Features/Input/CInputMousePositions.h
        src/Simulation/ECS/Features/Input/EInputContainer.h
        src/Simulation/Features/Shooting/CCannon.h
        src/Core/Storage/Config/ConfigSimulationKeys.h
        src/Simulation/Features/Shooting/CRequestFire.h
        src/Simulation/ECS/Features/Movable/CRequestMovement.h
        src/Simulation/Features/Shooting/SHandlerPlayerShoot.cpp
        src/Simulation/Features/Shooting/SHandlerPlayerShoot.h
        src/Simulation/ECS/Features/Input/SInputCleaner.cpp
        src/Simulation/ECS/Features/Input/SInputCleaner.h
        src/Simulation/Features/Player/SInputReader.h
        src/Simulation/Features/Player/SInputReader.cpp
        src/Core/Storage/Config/ConfigPlayer.h
        src/Core/Storage/Config/ConfigPlayerCannon.h
        src/Simulation/ECS/Features/Movable/CPhysics.h
        src/Simulation/ECS/ECS.h
        src/Simulation/GameLevels/Base/LevelCreatorsStorage.h
        src/Simulation/GameLevels/Base/LevelDataStorage.h
        src/Simulation/GameLevels/Base/LevelBase.h
        src/Simulation/Features/Timer/STimer.h
        src/Simulation/Features/Timer/STimer.cpp
        src/Simulation/Features/Background/EBackground.cpp
        src/Utility/Visual/PositionInRectangle.h
        src/Simulation/ECS/Features/Input/EInputContainer.cpp
        src/Simulation/Features/Timer/CTimer.h
        src/Simulation/Features/Timer/ETimer.cpp
        src/Utility/Math/Math.h
        src/Utility/Math/Math.cpp
        src/Simulation/ECS/Features/LifetimeControl/ESpawnerContainer.cpp
        src/Simulation/ECS/Features/Levels/ELevelState.cpp
        src/Simulation/ECS/Features/Debug/CText.h
        src/Simulation/ECS/Features/Debug/EDebugText.cpp
        src/Simulation/ECS/Features/Debug/EDebugText.h
        src/Utility/Visual/FontProvider.cpp
        src/Utility/Visual/FontProvider.h
        src/Utility/ResourcesCache.h
        src/Core/Application/ObjectsAggregator/GetterConfig.h
        src/Core/Application/ObjectsAggregator/GetterConfig.cpp
        src/Core/Application/ObjectsAggregator/GetterConfig.cpp
        src/Core/Application/ObjectsAggregator/GetterLog.cpp
        src/Core/Application/ObjectsAggregator/GetterLog.h
        src/Core/Application/ObjectsAggregator/GetterLevelProvider.cpp
        src/Core/Application/ObjectsAggregator/GetterLevelProvider.h
        src/Core/Application/ObjectsAggregator/GetterRandom.cpp
        src/Core/Application/ObjectsAggregator/GetterRandom.h
        src/Core/Application/ObjectsAggregator/GetterTextureProvider.cpp
        src/Core/Application/ObjectsAggregator/GetterTextureProvider.h
        src/Utility/TypeTraits.h
        src/Core/Storage/Config/ConfigFont.h
        src/Core/Storage/Config/ConfigResources.h
        src/Core/Storage/Config/ConfigFonts.h
        src/Core/Application/ObjectsAggregator/GetterFontProvider.cpp
        src/Core/Application/ObjectsAggregator/GetterFontProvider.h
        src/Core/Application/ObjectsAggregator/ObjectsAggregator.h
        src/Core/Application/ObjectsAggregator/GetterMenuLayer.cpp
        src/Core/Application/ObjectsAggregator/GetterMenuLayer.h
        src/Simulation/ECS/Features/Debug/SDebugInfo.cpp
        src/Simulation/ECS/Features/Debug/SDebugInfo.h
        src/Utility/Common.h
        src/Simulation/ECS/Features/Movable/CRotation.h
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

set(TestsLib ${PROJECT_NAME}TestsSource)
add_library(${TestsLib} STATIC ${TESTABLE_FILES})

foreach (TARGET ${PROJECT_NAME} ${TestsLib})
    add_dependencies(${TARGET} RapidJSON)
    add_dependencies(${TARGET} better_enums)
    target_link_libraries(${TARGET} PUBLIC sfml-system sfml-window sfml-graphics INTERFACE better_enums)
    target_include_directories(${TARGET} PUBLIC "src" ${better_enums_INCLUDE})
endforeach ()

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

add_custom_target(Run_GameTests
        COMMAND GameTests
        COMMENT "Running GameTests...")

add_dependencies(${PROJECT_NAME} Run_GameTests)
