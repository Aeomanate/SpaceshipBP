#include "GetterLevelProvider.h"
#include "Core/Application/Application.h"

LevelProvider& getLevelProvider()
{
    return Application::GetAggregatedObject<LevelProvider>();
}
