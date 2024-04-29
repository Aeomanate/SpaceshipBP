#ifndef SPACESHIPBP_CMOUSECLICKQUEUE_H
#define SPACESHIPBP_CMOUSECLICKQUEUE_H


#include "Simulation/ECS/Component.h"
#include <queue>
#include <SFML/System/Vector2.hpp>

struct CMouseClickQueue: public ECS::Component<CMouseClickQueue>
{
    std::queue<sf::Vector2f> queue;
};

#endif //SPACESHIPBP_CMOUSECLICKQUEUE_H
