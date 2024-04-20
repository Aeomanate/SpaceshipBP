#ifndef SPACESHIPBP_SENTITYMOVER_H
#define SPACESHIPBP_SENTITYMOVER_H


#include "Simulation/ECS/System.h"

class SEntityMover: public ECS::System
{
public:
    void Update(float dt) override;
};



#endif //SPACESHIPBP_SENTITYMOVER_H
