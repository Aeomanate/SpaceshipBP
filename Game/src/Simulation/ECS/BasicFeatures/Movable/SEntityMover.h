#ifndef SPACESHIPBP_SENTITYMOVER_H
#define SPACESHIPBP_SENTITYMOVER_H


#include "Simulation/ECS/System.h"

class SEntityMover: public ECS::System
{
protected:
    void Update(float dt) override;

public:

};



#endif //SPACESHIPBP_SENTITYMOVER_H
