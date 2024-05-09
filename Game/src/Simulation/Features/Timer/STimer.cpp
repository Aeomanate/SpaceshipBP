#include <cassert>
#include "STimer.h"
#include "CTimer.h"

void STimer::Update(float dt)
{
    for(auto& [eTimer, cTimer]: CTimer::All())
    {
        cTimer.value += dt;
    }

}
