#ifndef SPACESHIPBP_SLEVELSTATEFORWARDER_H
#define SPACESHIPBP_SLEVELSTATEFORWARDER_H


#include "Simulation/ECS/System.h"

class SLevelStateForwarder: public ECS::System
{
protected:
    void Update(float) override;

public:
    SLevelStateForwarder()
    : ECS::System(ECS::System::Order::POST_GAMEPLAY)
    { }
};


#endif //SPACESHIPBP_SLEVELSTATEFORWARDER_H
