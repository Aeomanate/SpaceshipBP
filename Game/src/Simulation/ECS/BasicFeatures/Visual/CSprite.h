#ifndef SPACESHIPBP_CSPRITE_H
#define SPACESHIPBP_CSPRITE_H


#include "SFML/Graphics.hpp"
#include "Simulation/ECS/Component.h"

struct CSprite: public ECS::Component<CSprite>
{
    sf::Sprite sprite;
};


#endif //SPACESHIPBP_CSPRITE_H
