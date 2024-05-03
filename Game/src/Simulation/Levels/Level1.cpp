#include "Level1.h"
#include "Simulation/Features/Player/EPlayer.h"
#include "Core/Application/ApplicationShortcuts.h"
#include "Simulation/ECS/ECS.h"
#include "Simulation/Features/Background/EBackground.h"

Level1::Level1()
{
    constexpr LevelDataStorage::MigrationPolicy transit = LevelDataStorage::MigrationPolicy::TRANSIT;
    constexpr LevelDataStorage::MigrationPolicy local = LevelDataStorage::MigrationPolicy::LOCAL;

    Add<SInputInjector, transit>();
    Add<SInputCleaner, transit>();

    Add<SEntityMover, transit>();
    Add<SCollisionDetector, transit>();

    Add<SSpriteAnimator, transit>();
    Add<SEntityDrawer, transit>();

    Add<SSpawner, transit>();
    Add<SDespawner, transit>();
    Add<ESpawnerContainer, transit>();

    Add<SLevelStateForwarder, transit>();
    Add<ELevelState, transit>();

    Add<EBackground, transit>();
    Add<EPlayer, transit>(getConfig().simulation.player);
}
