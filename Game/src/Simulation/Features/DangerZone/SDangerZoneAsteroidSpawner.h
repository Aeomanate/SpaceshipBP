#ifndef SPACESHIPBP_SDANGERZONEASTEROIDSPAWNER_H
#define SPACESHIPBP_SDANGERZONEASTEROIDSPAWNER_H

#include "Simulation/ECS/System.h"

class SDangerZoneAsteroidSpawner: public ECS::System
{
protected:
    void Update(float dt) override;

public:


};


#endif //SPACESHIPBP_SDANGERZONEASTEROIDSPAWNER_H
