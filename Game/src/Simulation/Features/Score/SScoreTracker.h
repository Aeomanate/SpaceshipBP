#ifndef SPACESHIPBP_SSCORETRACKER_H
#define SPACESHIPBP_SSCORETRACKER_H


#include "Simulation/ECS/System.h"

class SScoreTracker: public ECS::System
{
public:
    void Update(float dt) override;
};


#endif //SPACESHIPBP_SSCORETRACKER_H
