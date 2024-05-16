#include "LevelProviderGetter.h"
#include "Core/Application/Application.h"

LevelProvider& getLevelProvider()
{
    return Application::GetLevelProvider();
}
