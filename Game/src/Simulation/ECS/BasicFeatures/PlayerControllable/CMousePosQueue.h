#ifndef SPACESHIPBP_CMOUSEPOSQUEUE_H
#define SPACESHIPBP_CMOUSEPOSQUEUE_H


#include "Simulation/ECS/Component.h"
#include <queue>
#include <SFML/System/Vector2.hpp>

struct CMousePosQueue: public ECS::Component<CMousePosQueue>
{
    std::queue<sf::Vector2f> queue;
};

#endif //SPACESHIPBP_CMOUSEPOSQUEUE_H
