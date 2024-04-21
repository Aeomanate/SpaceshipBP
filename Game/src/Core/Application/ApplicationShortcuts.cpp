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

const GeneralConfig& getConfig()
{
    return Application::GetConfig().configGeneral;
}

const GeneralLocalization& getLoc()
{
    return Application::GetLoc();
}

Random& getRnd()
{
    return Application::GetRnd();
}
