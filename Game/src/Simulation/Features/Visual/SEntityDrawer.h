#ifndef SPACESHIPBP_SENTITYDRAWER_H
#define SPACESHIPBP_SENTITYDRAWER_H


#include <SFML/Graphics.hpp>
#include "Simulation/ECS/System.h"

class SEntityDrawer: public ECS::System
{
public:
    SEntityDrawer(sf::RenderTarget* renderTarget);

    void Update(float) override;

private:
    sf::RenderTarget* renderTarget;
};


#endif //SPACESHIPBP_SENTITYDRAWER_H
