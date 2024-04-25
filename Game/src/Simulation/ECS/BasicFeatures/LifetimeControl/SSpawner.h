#ifndef SPACESHIPBP_SSPAWNER_H
#define SPACESHIPBP_SSPAWNER_H


#include "Simulation/ECS/System.h"

class SSpawner: ECS::System
{
public:
    void Update(float dt) override;

};


#endif //SPACESHIPBP_SSPAWNER_H
