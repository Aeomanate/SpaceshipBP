#include "ApplicationShortcuts.h"
#include "Application.h"

MenuLayer& getMenuLayer()
{
    return Application::GetMenuLayer();
}

const Simulation& getSimulation()
{
    return Application::GetSimulation();
}

const GeneralConfig& getConfig()
{
    return Application::GetConfig();
}

const GeneralLocalization& getLoc()
{
    return Application::GetLoc();
}

const TextureProvider& getTextureProvider()
{
    return Application::GetTextureProvider();
}

LevelProvider& getLevelProvider()
{
    return Application::GetLevelProvider();
}

Random& getRnd()
{
    return Application::GetRnd();
}
