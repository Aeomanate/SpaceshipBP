#include "SLevelStateForwarder.h"
#include "CLevelState.h"
#include "Core/Application/ApplicationShortcuts.h"

void SLevelStateForwarder::Update(float)
{
    LevelState cachedState = getLevelProvider().GetCurrentLevel().GetCachedLevelState();

    auto stateOpt = CLevelState::TryGetFirst();

    if(stateOpt && stateOpt.value().state != cachedState)
    {
        getLevelProvider().GetCurrentLevel().SetCachedLevelState(stateOpt.value().state);
    }
}
