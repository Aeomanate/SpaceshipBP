#ifndef SPACESHIPBP_STEXTHANDLER_H
#define SPACESHIPBP_STEXTHANDLER_H


#include "Simulation/ECS/System.h"

class STextHandler: public ECS::System
{
protected:
    void Update(float dt) override;
};


#endif //SPACESHIPBP_STEXTHANDLER_H
