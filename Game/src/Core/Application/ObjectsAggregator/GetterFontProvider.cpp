#include "GetterFontProvider.h"
#include "Core/Application/Application.h"

const FontsCache& getFontsCache()
{
    return Application::GetAggregatedObject<FontsCache>();
}
