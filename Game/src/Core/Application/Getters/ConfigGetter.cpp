#include "ConfigGetter.h"
#include "Core/Application/Application.h"

const GeneralConfig& getConfig()
{
    return Application::GetConfig();
}
