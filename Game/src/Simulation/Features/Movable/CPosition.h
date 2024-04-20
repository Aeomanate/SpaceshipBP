#ifndef SPACESHIPBP_CPOSITION_H
#define SPACESHIPBP_CPOSITION_H


#include "Simulation/ECS/Component.h"
#include "SFML/System/Vector2.hpp"

struct CPosition: public sf::Vector2f, public ECS::Component<CPosition>
{

};


#endif //SPACESHIPBP_CPOSITION_H
