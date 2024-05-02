#ifndef SPACESHIPBP_SSPAWNER_H
#define SPACESHIPBP_SSPAWNER_H


#include "Simulation/ECS/System.h"

class SSpawner: public ECS::System
{
protected:
    void Update(float dt) override;

public:
    SSpawner()
    : ECS::System(ECS::System::Order::PRE_GAMEPLAY)
    { }

};


#endif //SPACESHIPBP_SSPAWNER_H
