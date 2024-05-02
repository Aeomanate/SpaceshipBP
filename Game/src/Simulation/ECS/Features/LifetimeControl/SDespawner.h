#ifndef SPACESHIPBP_SDESPAWNER_H
#define SPACESHIPBP_SDESPAWNER_H


#include "Simulation/ECS/System.h"

class SDespawner: public ECS::System
{
protected:
    void Update(float dt) override;

public:
    SDespawner()
    : ECS::System(ECS::System::Order::POST_GAMEPLAY)
    { }

};


#endif //SPACESHIPBP_SDESPAWNER_H
