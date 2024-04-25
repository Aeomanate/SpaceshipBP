#ifndef SPACESHIPBP_CDANGERZONESTAT_H
#define SPACESHIPBP_CDANGERZONESTAT_H

#include "Simulation/ECS/Component.h"
#include "SFML/System/Vector2.hpp"
#include "SFML/Config.hpp"

struct CDangerZoneStat: public ECS::Component<CDangerZoneStat>
{
    float timeInZone = 0;
    bool isPlayerInZone = false;
};

#endif //SPACESHIPBP_CDANGERZONESTAT_H
