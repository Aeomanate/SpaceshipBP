#ifndef SPACESHIPBP_CREQUESTMOVEMENT_H
#define SPACESHIPBP_CREQUESTMOVEMENT_H

#include "Simulation/ECS/Component.h"
#include "SFML/System/Vector2.hpp"

struct CRequestMovement: public ECS::Component<CRequestMovement, sf::Vector2f>
{

};

#endif //SPACESHIPBP_CREQUESTMOVEMENT_H
