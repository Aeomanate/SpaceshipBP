#include "Level1.h"
#include "Simulation/Features/Player/EPlayer.h"

Level1::Level1()
{
    constexpr LevelDataStorage::MigrationPolicy transit = LevelDataStorage::MigrationPolicy::TRANSIT;
    constexpr LevelDataStorage::MigrationPolicy local = LevelDataStorage::MigrationPolicy::LOCAL;

    Add<EPlayer, transit>();

    InjectStorages();
}
