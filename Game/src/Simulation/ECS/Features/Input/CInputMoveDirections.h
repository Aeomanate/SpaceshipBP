#ifndef SPACESHIPBP_CINPUTMOVEDIRECTIONS_H
#define SPACESHIPBP_CINPUTMOVEDIRECTIONS_H

#include <SFML/System/Vector2.hpp>
#include <queue>
#include "Simulation/ECS/Component.h"

struct CInputMoveDirections: public ECS::Component<CInputMoveDirections, std::queue<sf::Vector2f>>
{

};

#endif //SPACESHIPBP_CINPUTMOVEDIRECTIONS_H
