#ifndef SPACESHIPBP_CAPPLIEDFORCES_H
#define SPACESHIPBP_CAPPLIEDFORCES_H


#include "SFML/System/Vector2.hpp"
#include "Simulation/ECS/Component.h"

struct CAppliedForces: public sf::Vector2f, public ECS::Component<CAppliedForces>
{

};


#endif //SPACESHIPBP_CAPPLIEDFORCES_H
