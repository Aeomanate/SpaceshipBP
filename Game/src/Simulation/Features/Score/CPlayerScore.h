#ifndef SPACESHIPBP_CPLAYERSCORE_H
#define SPACESHIPBP_CPLAYERSCORE_H

#include "Simulation/ECS/Component.h"
#include "SFML/Config.hpp"

struct CPlayerScore: public ECS::Component<CPlayerScore>
{
    sf::Uint32 earnedScore = 0;
    float timeInGame = 0;
};

#endif //SPACESHIPBP_CPLAYERSCORE_H
