#ifndef SPACESHIPBP_CINPUTMOUSEPOSITIONS_H
#define SPACESHIPBP_CINPUTMOUSEPOSITIONS_H

#include <queue>
#include <SFML/System/Vector2.hpp>
#include "Simulation/ECS/Component.h"

struct CInputMousePositions: public ECS::Component<CInputMousePositions, std::queue<sf::Vector2f>>
{

};

#endif //SPACESHIPBP_CINPUTMOUSEPOSITIONS_H
