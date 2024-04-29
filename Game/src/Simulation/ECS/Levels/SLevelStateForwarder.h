#ifndef SPACESHIPBP_SLEVELSTATEFORWARDER_H
#define SPACESHIPBP_SLEVELSTATEFORWARDER_H


#include "Simulation/ECS/System.h"

class SLevelStateForwarder: public ECS::System
{
public:
    void Update(float) override;
};


#endif //SPACESHIPBP_SLEVELSTATEFORWARDER_H
