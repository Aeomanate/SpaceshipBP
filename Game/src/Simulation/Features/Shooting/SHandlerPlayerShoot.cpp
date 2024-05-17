#include "SHandlerPlayerShoot.h"
#include "CCannon.h"
#include "Simulation/ECS/ECS.h"

void SHandlerPlayerShoot::Update(float dt)
{
    auto clicksPos = CInputMouseClicks::TryGetFirstDataPtr();
    if(clicksPos && !(*clicksPos)->empty())
    {
        auto& [player, cannon] = *CCannon::All().begin();
    }
}
