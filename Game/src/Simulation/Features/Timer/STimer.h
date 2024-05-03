#ifndef SPACESHIPBP_STIMER_H
#define SPACESHIPBP_STIMER_H

#include "Simulation/ECS/System.h"

class STimer: public ECS::System
{
protected:
    void Update(float dt) override;
};

#endif //SPACESHIPBP_STIMER_H
