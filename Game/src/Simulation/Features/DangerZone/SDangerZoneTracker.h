#ifndef SPACESHIPBP_SDANGERZONETRACKER_H
#define SPACESHIPBP_SDANGERZONETRACKER_H

#include "Simulation/ECS/System.h"

class SDangerZoneTracker: public ECS::System
{
protected:
    void Update(float dt) override;

public:

};


#endif //SPACESHIPBP_SDANGERZONETRACKER_H
