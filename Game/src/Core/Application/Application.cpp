#include "Application.h"


Application::Application()
{
}

void Application::Init()
{
    ListenersInit();

    rootConfig.Init(getConfig().path.configFolder, getConfig().path.configName);
    rootConfig.LoadOrCreate();

    rootLocalization.Init(getConfig().path.localizationFolder, getConfig().path.localizationName);
    rootLocalization.LoadOrCreate();


    ConfigWindow const& windowParams = rootConfig.configGeneral.window;
    Setup(windowParams.videoMode, windowParams.name, windowParams.style);
}

void Application::ListenersInit()
{
    listenerKeyPressed.SubscribeEmitter(emitterKeyEvent);

    listenerLastMenuClosed.SubscribeEmitter(menuManager.emitterLastMenuClosed);

    simulation.listenerKeyPressed.SubscribeEmitter(emitterKeyEvent);
    simulation.listenerMouseButtonClicked.SubscribeEmitter(emitterMouseClicked);
}

Simulation const& Application::GetSimulation()
{
    return GetInstance()->simulation;
}

MenuManager& Application::GetMenuManager()
{
    return GetInstance()->menuManager;
}

GeneralLocalization const& Application::GetLoc()
{
    return GetInstance()->rootLocalization.localization;
}

RootConfig const& Application::GetConfig()
{
    return GetInstance()->rootConfig;
}

TextureProvider const& Application::GetTextureProvider()
{
    return GetInstance()->textureProvider;
}

Random& Application::GetRnd()
{
    return GetInstance()->random;
}


void Application::Update()
{

}

void Application::Draw()
{
    window.clear(sf::Color::Black);
    window.display();
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

Application::~Application()
{

}

void Application::FinishWork()
{
    rootConfig.Save();
    rootLocalization.Save();
}

