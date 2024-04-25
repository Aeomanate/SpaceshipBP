#include "Application.h"
#include "ApplicationShortcuts.h"
using namespace std::string_literals;


Application::Application()
{
}

void Application::Init()
{
    Log("\n\n"s + *getLoc().application.started, "");

    InitListeners();
    InitStorages();


    ConfigWindow const& windowParams = rootConfig.configGeneral.window;
    Setup(windowParams.videoMode, windowParams.name, windowParams.style);
}

void Application::InitListeners()
{
    listenerKeyPressed.SubscribeEmitter(emitterKeyEvent);
    listenerLastMenuClosed.SubscribeEmitter(menuLayer.emitterLastMenuClosed);
}

void Application::InitStorages()
{
    rootConfig.Init(getConfig().path.configFolder, getConfig().path.configName);
    rootConfig.LoadOrCreate();

    rootLocalization.Init(getConfig().path.localizationFolder, getConfig().path.localizationName);
    rootLocalization.LoadOrCreate();
}

void Application::InitGameRelated()
{
    textureProvider.LoadTextures();

}

Simulation const& Application::GetSimulation()
{
    return GetInstance()->simulation;
}

MenuLayer& Application::GetMenuLayer()
{
    return GetInstance()->menuLayer;
}

GeneralLocalization const& Application::GetLoc()
{
    return GetInstance()->rootLocalization.localization;
}

GeneralConfig const& Application::GetConfig()
{
    return GetInstance()->rootConfig.configGeneral;
}


TextureProvider const& Application::GetTextureProvider()
{
    return GetInstance()->textureProvider;
}

Random& Application::GetRnd()
{
    return GetInstance()->random;
}

LevelProvider& Application::GetLevelProvider()
{
    return GetInstance()->levelProvider;
}

void Application::Update()
{

}

void Application::Draw()
{
    window.clear(sf::Color::Black);
    window.display();
}

void Application::FinishWork()
{
    Log(getLoc().application.closed, "");

    rootConfig.Save();
    rootLocalization.Save();
}

void Application::OnLastMenuClosed()
{
    isLowLevelApplicationWork = false;
}

void Application::OnKeyPressed(const sf::Event::KeyEvent& key)
{
    if(key.code == sf::Keyboard::Escape)
    {
        isLowLevelApplicationWork = false;
    }
}

