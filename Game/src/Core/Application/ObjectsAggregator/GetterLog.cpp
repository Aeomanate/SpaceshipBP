#include "GetterLog.h"
#include "Core/Application/Application.h"

const GeneralLocalization& getLoc()
{
    return Application::GetAggregatedObject<RootLocalization>().localization;
}
