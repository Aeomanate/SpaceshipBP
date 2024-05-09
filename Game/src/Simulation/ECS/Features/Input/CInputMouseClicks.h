#ifndef SPACESHIPBP_CINPUTMOUSECLICKS_H
#define SPACESHIPBP_CINPUTMOUSECLICKS_H

#include <queue>
#include <SFML/System/Vector2.hpp>
#include "Simulation/ECS/Component.h"

struct CInputMouseClicks: public ECS::Component<CInputMouseClicks, std::queue<sf::Vector2f>>
{

};

#endif //SPACESHIPBP_CINPUTMOUSECLICKS_H
