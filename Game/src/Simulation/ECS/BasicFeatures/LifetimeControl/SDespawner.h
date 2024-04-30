#ifndef SPACESHIPBP_SDESPAWNER_H
#define SPACESHIPBP_SDESPAWNER_H


#include "Simulation/ECS/System.h"

class SDespawner: public ECS::System
{
protected:
    void Update(float dt) override;

public:


};


#endif //SPACESHIPBP_SDESPAWNER_H
