#ifndef SPACESHIPBP_SDANGERZONEASTEROIDSPAWNER_H
#define SPACESHIPBP_SDANGERZONEASTEROIDSPAWNER_H

#include "Simulation/ECS/System.h"

class SDangerZoneAsteroidSpawner: public ECS::System
{
public:
    void Update(float dt) override;

};


#endif //SPACESHIPBP_SDANGERZONEASTEROIDSPAWNER_H
