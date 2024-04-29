#ifndef SPACESHIPBP_CMOVEMENTDIRECTIONQUEUE_H
#define SPACESHIPBP_CMOVEMENTDIRECTIONQUEUE_H

#include "Simulation/ECS/Component.h"
#include <queue>
#include <SFML/System/Vector2.hpp>

struct CMovementDirectionQueue: public ECS::Component<CMovementDirectionQueue>
{
    std::queue<sf::Vector2f> queue;
};

#endif //SPACESHIPBP_CMOVEMENTDIRECTIONQUEUE_H
