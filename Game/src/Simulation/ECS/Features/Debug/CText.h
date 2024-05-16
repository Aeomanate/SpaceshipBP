#ifndef SPACESHIPBP_CTEXT_H
#define SPACESHIPBP_CTEXT_H

#include "Simulation/ECS/Component.h"
#include "SFML/Graphics/Text.hpp"

struct CText: public ECS::Component<CText, sf::Text>
{

};

#endif //SPACESHIPBP_CTEXT_H
