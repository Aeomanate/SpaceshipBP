#ifndef SPACESHIPBP_SDESPAWNER_H
#define SPACESHIPBP_SDESPAWNER_H


#include "Simulation/ECS/System.h"

class SDespawner: public ECS::System
{
public:
    void Update(float dt) override;

};


#endif //SPACESHIPBP_SDESPAWNER_H
