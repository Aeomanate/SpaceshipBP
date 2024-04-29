#ifndef SPACESHIPBP_SINPUTINJECTOR_H
#define SPACESHIPBP_SINPUTINJECTOR_H


#include "Simulation/ECS/System.h"
#include "SFML/Window/Event.hpp"

class SInputInjector: public ECS::System
{
public:
    void Update(float dt) override;

    void InjectMovement(sf::Vector2f direction);
    void InjectMouseClick(sf::Vector2f position);
    void InjectMousePosition(sf::Vector2f position);
};


#endif //SPACESHIPBP_SINPUTINJECTOR_H
