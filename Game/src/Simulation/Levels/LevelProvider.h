#ifndef SPACESHIPBP_LEVELPROVIDER_H
#define SPACESHIPBP_LEVELPROVIDER_H

#include <unordered_map>
#include <string>
#include "Level.h"
#include "Core/Storage/Config/ConfigLevel.h"

class LevelProvider
{
public:
    void Init();

    Level& LoadLevel(const ConfigLevel& configLevel);
    Level& LoadNextLevel();

    const ConfigLevel& getCurrentLevelConfig() const;

private:
    ConfigLevel* currentLevelConfig;
    std::unique_ptr<Level> currentLevel;
};


#endif //SPACESHIPBP_LEVELPROVIDER_H
