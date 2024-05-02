#ifndef SPACESHIPBP_LEVELPROVIDER_H
#define SPACESHIPBP_LEVELPROVIDER_H

#include <unordered_map>
#include <string>
#include "Core/Storage/Config/ConfigLevel.h"

class Level;
class LevelProvider
{
public:
    void Init();

    Level* LoadLevel(const ConfigLevel& configLevel);
    Level* LoadNextLevel();

    const ConfigLevel& GetCurrentLevelConfig() const;
    const Level& GetCurrentLevel() const;
    Level& GetCurrentLevel();

private:
    ConfigLevel* currentLevelConfig;
    std::unique_ptr<Level> currentLevel;
};


#endif //SPACESHIPBP_LEVELPROVIDER_H
