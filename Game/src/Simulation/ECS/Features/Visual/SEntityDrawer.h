#ifndef SPACESHIPBP_SENTITYDRAWER_H
#define SPACESHIPBP_SENTITYDRAWER_H


#include "SFML/Graphics.hpp"
#include "Simulation/ECS/System.h"

class SEntityDrawer: public ECS::System
{
protected:
    void Update(float) override;

public:
    SEntityDrawer();

    sf::Sprite GetDrawnState();

private:
    sf::RenderTexture renderTexture;
};


#endif //SPACESHIPBP_SENTITYDRAWER_H
