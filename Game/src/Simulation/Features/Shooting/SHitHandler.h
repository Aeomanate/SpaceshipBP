#ifndef SPACESHIPBP_SHITHANDLER_H
#define SPACESHIPBP_SHITHANDLER_H


#include "Simulation/ECS/System.h"

class SHitHandler: public ECS::System
{
public:
    void Update(float dt) override;

};


#endif //SPACESHIPBP_SHITHANDLER_H
