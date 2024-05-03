#ifndef SPACESHIPBP_LEVELPROVIDER_H
#define SPACESHIPBP_LEVELPROVIDER_H

#include <unordered_map>
#include <string>
#include <memory>
#include "Core/Storage/Config/ConfigLevel.h"
#include "Level.h"


class LevelProvider
{
public:
    void Init();

    LevelBase* LoadLevel(const ConfigLevel& configLevel);

    const ConfigLevel& GetCurrentLevelConfig() const;
    const LevelBase& GetCurrentLevel() const;
    LevelBase& GetCurrentLevel();

private:
    ConfigLevel* currentLevelConfig;
    std::unique_ptr<LevelBase> currentLevel;
};


#endif //SPACESHIPBP_LEVELPROVIDER_H
