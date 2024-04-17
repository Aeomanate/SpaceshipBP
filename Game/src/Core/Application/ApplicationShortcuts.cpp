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

const ConfigGeneral& getConfig()
{
    return Application::GetConfig().configGeneral;
}

const ApplicationLocalization& getLoc()
{
    return Application::GetLoc();
}
