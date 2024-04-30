#ifndef SPACESHIPBP_SSCORETRACKER_H
#define SPACESHIPBP_SSCORETRACKER_H


#include "Simulation/ECS/System.h"

class SScoreTracker: public ECS::System
{
protected:
    void Update(float dt) override;

public:

};


#endif //SPACESHIPBP_SSCORETRACKER_H
