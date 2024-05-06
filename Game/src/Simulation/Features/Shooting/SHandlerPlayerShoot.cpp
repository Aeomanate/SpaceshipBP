#include "SHandlerPlayerShoot.h"
#include "CCannon.h"
#include "Simulation/ECS/Features/Input/CQueueMouseClicks.h"

void SHandlerPlayerShoot::Update(float dt)
{
    auto clicksPos = CQueueMouseClicks::TryGetFirst();
    if(clicksPos && !clicksPos.value()->empty())
    {
        auto& [player, cannon] = *CCannon::All().begin();

    }
}
