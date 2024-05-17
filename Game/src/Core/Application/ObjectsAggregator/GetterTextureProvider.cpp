#include "GetterTextureProvider.h"
#include "Core/Application/Application.h"

const TexturesCache& getTextureProvider()
{
    return Application::GetAggregatedObject<TexturesCache>();
}
