#include "ApplicationShortcuts.h"
#include "Application.h"


Simulation const& Application::GetSimulation()
{
    return GetInstance()->simulation;
}

MenuManager& Application::GetMenuManager()
{
    return GetInstance()->menuManager;
}

Config const& Application::GetConfig()
{
    return GetInstance()->config;
}

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
