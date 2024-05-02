#ifndef SPACESHIPBP_SSPRITEANIMATOR_H
#define SPACESHIPBP_SSPRITEANIMATOR_H


#include "Simulation/ECS/System.h"

class SSpriteAnimator: public ECS::System
{
protected:
    void Update(float dt) override;

};


#endif //SPACESHIPBP_SSPRITEANIMATOR_H
