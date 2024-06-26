#include "SLevelStateForwarder.h"
#include "CLevelState.h"
#include "Core/Application/ApplicationShortcuts.h"

void SLevelStateForwarder::Update(float)
{
    LevelState cachedState = getLevelProvider().GetCurrentLevel().GetCachedLevelState();

    auto statePtr = CLevelState::TryGetFirstDataPtr();

    if(statePtr && statePtr->value != cachedState)
    {
        getLevelProvider().GetCurrentLevel().SetCachedLevelState(statePtr->value);
    }
}
