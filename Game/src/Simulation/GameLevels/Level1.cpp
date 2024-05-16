#include "Level1.h"
#include "Simulation/Features/Player/EPlayer.h"
#include "Core/Application/Getters/ConfigGetter.h"
#include "Simulation/ECS/ECS.h"
#include "Simulation/Features/Background/EBackground.h"
#include "Simulation/Features/Player/SInputReader.h"
#include "Simulation/Features/Timer/ETimer.h"
#include "Simulation/Features/Timer/STimer.h"

Level1::Level1()
{

    AddAs<LevelDataStorage::MigrationPolicy::TRANSIT>()
    .Add<ETimer>()
    .Add<STimer>()

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
