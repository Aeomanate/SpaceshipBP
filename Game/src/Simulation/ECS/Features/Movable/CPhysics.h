#ifndef SPACESHIPBP_CPHYSICS_H
#define SPACESHIPBP_CPHYSICS_H

#include "Simulation/ECS/Component.h"
#include "SFML/System/Vector2.hpp"
#include "Utility/Serialization/ImplSerializable.h"

struct CPhysics: ECS::Component<CPhysics>
{
    float mass;
    sf::Vector2f speed;
    sf::Vector2f appliedForces;
};

#endif //SPACESHIPBP_CPHYSICS_H
