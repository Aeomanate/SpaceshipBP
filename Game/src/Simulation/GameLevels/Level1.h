#ifndef SPACESHIPBP_LEVEL1_H
#define SPACESHIPBP_LEVEL1_H


#include "Simulation/GameLevels/Base/Level.h"
#include "Simulation/GameLevels/Base/LevelCreatorsStorage.h"
#include "Core/Storage/Config/ConfigLevels.h"

class Level1: public Level<Level1, &ConfigLevels::level1>
{
public:
    Level1();
    Level1(LevelPtr) { }
};


#endif //SPACESHIPBP_LEVEL1_H
