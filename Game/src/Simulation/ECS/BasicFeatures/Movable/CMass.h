#ifndef SPACESHIPBP_CMASS_H
#define SPACESHIPBP_CMASS_H


#include "Simulation/ECS/Component.h"

struct CMass: public ECS::Component<CMass>
{
    float m;
};


#endif //SPACESHIPBP_CMASS_H
