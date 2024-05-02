#include "SHandlerPlayerShoot.h"
#include "CCannon.h"
#include "Simulation/ECS/Features/Input/CQueueMouseClicks.h"

void SHandlerPlayerShoot::Update(float dt)
{
    auto& clicksPos = CQueueMouseClicks::AllEntities().begin()->second;
    if(!clicksPos.queue.empty())
    {
        auto& [player, cannon] = *CCannon::AllEntities().begin();

    }
}
