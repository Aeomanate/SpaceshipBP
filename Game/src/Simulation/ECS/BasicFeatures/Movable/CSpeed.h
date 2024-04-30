#ifndef SPACESHIPBP_CSPEED_H
#define SPACESHIPBP_CSPEED_H


#include "Simulation/ECS/Component.h"

#include "Simulation/ECS/Component.h"
#include <SFML/System/Vector2.hpp>

struct CSpeed: public ECS::Component<CSpeed>
{
    sf::Vector2f value;
};


#endif //SPACESHIPBP_CSPEED_H
