#ifndef SPACESHIPBP_CSPEED_H
#define SPACESHIPBP_CSPEED_H


#include "Simulation/ECS/Component.h"

#include "Simulation/ECS/Component.h"
#include "SFML/System/Vector2.hpp"

struct CSpeed: public sf::Vector2f, public ECS::Component<CSpeed>
{

};


#endif //SPACESHIPBP_CSPEED_H
