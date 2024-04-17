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

const ConfigApplication& getConfig()
{
    return Application::GetConfig().applicationConfig;
}

const ApplicationLocalization& getLoc()
{
    return Application::GetLoc();
}
