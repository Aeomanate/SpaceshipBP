#include "SLevelStateForwarder.h"
#include "CLevelState.h"
#include "Core/Application/ApplicationShortcuts.h"

void SLevelStateForwarder::Update(float)
{
    LevelState cachedState = getLevelProvider().GetCurrentLevel().GetCachedLevelState();

    const auto& [it, curState] = *CLevelState::AllEntities().begin();

    if(curState.state != cachedState)
    {
        getLevelProvider().GetCurrentLevel().SetCachedLevelState(curState.state);
    }
}
