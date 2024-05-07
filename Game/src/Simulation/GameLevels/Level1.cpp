#include "Level1.h"
#include "Simulation/Features/Player/EPlayer.h"
#include "Core/Application/ApplicationShortcuts.h"
#include "Simulation/ECS/ECS.h"
#include "Simulation/Features/Background/EBackground.h"
#include "Simulation/Features/Player/SInputReader.h"

Level1::Level1()
{
    AddAs<LevelDataStorage::MigrationPolicy::TRANSIT>()
    .Add<EInputContainer>()
    .Add<SInputInjector>()
    .Add<SInputCleaner>()

    .Add<SEntityMover>()
    .Add<SCollisionDetector>()

    .Add<SSpriteAnimator>()
    .Add<SEntityDrawer>()

    .Add<SSpawner>()
    .Add<SDespawner>()
    .Add<ESpawnerContainer>()

    .Add<SLevelStateForwarder>()
    .Add<ELevelState>()

    .Add<EBackground>()

    .Add<SInputReader>()
    .Add<EPlayer>(getConfig().simulation.player);

}
