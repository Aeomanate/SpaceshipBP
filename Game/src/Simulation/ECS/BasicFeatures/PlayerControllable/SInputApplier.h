#ifndef SPACESHIPBP_SINPUTAPPLIER_H
#define SPACESHIPBP_SINPUTAPPLIER_H


#include "Simulation/ECS/System.h"

class SInputApplier: ECS::System
{
public:
    void Update(float dt) override;

};


#endif //SPACESHIPBP_SINPUTAPPLIER_H
