#ifndef SPACESHIPBP_EPLAYER_H
#define SPACESHIPBP_EPLAYER_H

#include "Simulation/ECS/Entity.h"
#include "Core/Storage/Config/ConfigPlayer.h"

struct EPlayer: public ECS::Entity
{
    EPlayer(const ConfigPlayer& configPlayer);
};

#endif //SPACESHIPBP_EPLAYER_H
