#include "ApplicationShortcuts.h"
#include "Application.h"

MenuManager& getMenuManager()
{
    return Application::GetMenuManager();
}

const Simulation& getSimulation()
{
    return Application::GetSimulation();
}

const Config& getConfig()
{
    return Application::GetConfig();
}

const ConfigLocalization& getLoc()
{
    return getConfig().localization;
}
