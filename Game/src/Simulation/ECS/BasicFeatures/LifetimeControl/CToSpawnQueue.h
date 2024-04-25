#ifndef SPACESHIPBP_CTOSPAWNQUEUE_H
#define SPACESHIPBP_CTOSPAWNQUEUE_H

#include "Simulation/ECS/Component.h"
#include <queue>
#include <memory>
#include "Simulation/ECS/Entity.h"

struct CToSpawnQueue: public ECS::Component<CToSpawnQueue>
{
    std::queue<std::unique_ptr<ECS::Entity>> waitingEntities;
};

#endif //SPACESHIPBP_CTOSPAWNQUEUE_H
