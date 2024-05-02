#include "LevelProvider.h"
#include "Core/Application/ApplicationShortcuts.h"

void LevelProvider::Init()
{

}

Level* LevelProvider::LoadLevel(const ConfigLevel& configLevel)
{
    Log(getLoc().simulation.levelLoadingNotify, configLevel.name);

    // TODO Implement fabric of levels by their names
    currentLevel = std::make_unique<Level>();
    if(currentLevel)
    {
        Log(getLoc().simulation.levelLoadingSuccessfulNotify, configLevel.name);
    }
    else
    {
        Log(getLoc().simulation.levelLoadingFailedWarning, configLevel.name, Logger::Level::WARNING);
    }
    return  currentLevel.get();
}

Level* LevelProvider::LoadNextLevel()
{
    return nullptr;
}

const ConfigLevel& LevelProvider::GetCurrentLevelConfig() const
{
    return *currentLevelConfig;
}

const Level& LevelProvider::GetCurrentLevel() const
{
    return *currentLevel;
}

Level& LevelProvider::GetCurrentLevel()
{
    return *currentLevel;
}
