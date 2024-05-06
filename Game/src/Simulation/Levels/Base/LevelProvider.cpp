#include "LevelProvider.h"
#include "Core/Application/ApplicationShortcuts.h"
#include "Simulation/Levels/Base/LevelBase.h"

LevelBase* LevelProvider::LoadLevel(const ConfigLevel& configLevel)
{
    Log(getLoc().simulation.levelLoadingNotify, configLevel.name);
    LevelBase::LevelPtr nextLevel = nullptr;
    if(currentLevel)
    { nextLevel = LevelCreatorsStorage::Create(configLevel, std::move(currentLevel)); }
    else
    { nextLevel = LevelCreatorsStorage::Create(configLevel); }

    currentLevel = std::move(nextLevel);

    if(currentLevel)
    { Log(getLoc().simulation.levelLoadingSuccessfulNotify, configLevel.name); }
    else
    { Log(getLoc().simulation.levelLoadingFailedWarning, configLevel.name, Logger::Level::WARNING); }

    currentLevelConfig = &configLevel;
    return  currentLevel.get();
}

const ConfigLevel& LevelProvider::GetCurrentLevelConfig() const
{
    return *currentLevelConfig;
}

const LevelBase& LevelProvider::GetCurrentLevel() const
{
    return *currentLevel;
}

LevelBase& LevelProvider::GetCurrentLevel()
{
    return *currentLevel;
}
