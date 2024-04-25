#ifndef SPACESHIPBP_CINPUTQUEUE_H
#define SPACESHIPBP_CINPUTQUEUE_H

#include "Simulation/ECS/Component.h"
#include <queue>
#include <SFML/System/Vector2.hpp>

struct CInputQueue: public ECS::Component<CInputQueue>
{
    std::queue<sf::Vector2f> accelerationQueue;
};

#endif //SPACESHIPBP_CINPUTQUEUE_H
