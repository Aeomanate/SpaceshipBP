#include "TextureProviderGetter.h"
#include "Core/Application/Application.h"

const TextureProvider& getTextureProvider()
{
    return Application::GetTextureProvider();
}
