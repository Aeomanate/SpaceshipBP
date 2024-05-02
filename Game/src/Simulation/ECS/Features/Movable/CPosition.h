#ifndef SPACESHIPBP_CPOSITION_H
#define SPACESHIPBP_CPOSITION_H


#include "Simulation/ECS/Component.h"
#include "SFML/System/Vector2.hpp"

struct CPosition: public ECS::SimpleComponent<sf::Vector2f>
{

};


#endif //SPACESHIPBP_CPOSITION_H
