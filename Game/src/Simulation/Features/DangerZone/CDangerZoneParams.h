#ifndef SPACESHIPBP_CDANGERZONEPARAMS_H
#define SPACESHIPBP_CDANGERZONEPARAMS_H

#include "Simulation/ECS/Component.h"
#include "SFML/System/Vector2.hpp"
#include "SFML/Config.hpp"

struct CDangerZoneParams: public ECS::Component<CDangerZoneParams>
{
    sf::Vector2u pos;
    sf::Uint32 radius;
    float timeToPass;
};

#endif //SPACESHIPBP_CDANGERZONEPARAMS_H
