#include "GetterConfig.h"
#include "Core/Application/Application.h"

const GeneralConfig& getConfig()
{
    return Application::GetAggregatedObject<RootConfig>().configGeneral;
}
