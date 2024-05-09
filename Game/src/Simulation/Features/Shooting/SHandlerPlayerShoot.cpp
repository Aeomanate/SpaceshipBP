#include "SHandlerPlayerShoot.h"
#include "CCannon.h"
#include "Simulation/ECS/Features/Input/CInputMouseClicks.h"

void SHandlerPlayerShoot::Update(float dt)
{
    auto clicksPos = CInputMouseClicks::TryGetFirstDataPtr();
    if(clicksPos && !(*clicksPos)->empty())
    {
        auto& [player, cannon] = *CCannon::All().begin();
    }
}
