#ifndef SPACESHIPBP_CAPPLIEDFORCES_H
#define SPACESHIPBP_CAPPLIEDFORCES_H


#include <SFML/System/Vector2.hpp>
#include "Simulation/ECS/Component.h"

struct CAppliedForces: public ECS::Component<CAppliedForces>
{
    sf::Vector2f value;
};


#endif //SPACESHIPBP_CAPPLIEDFORCES_H
