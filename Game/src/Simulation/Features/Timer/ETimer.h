#ifndef SPACESHIPBP_ETIMER_H
#define SPACESHIPBP_ETIMER_H


#include "Simulation/ECS/Entity.h"
#include "SFML/System/Clock.hpp"

struct ETimer: public ECS::Entity
{
    ETimer();
};

#endif //SPACESHIPBP_ETIMER_H
