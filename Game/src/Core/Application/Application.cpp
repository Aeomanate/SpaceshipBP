#include "Application.h"
#include "Getters/LogGetter.h"

using namespace std::string_literals;

Application& Application::Init()
{
    Logger::GlobalLogLevel = Logger::Level::VERBOSE;

    Log("\n\n"s + *getLoc().application.started, "");

    InitListeners();
    InitStorages();
    InitGameRelated();

    ConfigWindow const& windowParams = rootConfig.configGeneral.window;
    Setup(windowParams.videoMode, windowParams.name, windowParams.style);

    return *this;
}

void Application::InitListeners()
{
    listenerKeyPressed.SubscribeEmitter(emitterKey);
    listenerLastMenuClosed.SubscribeEmitter(menuLayer.emitterLastMenuClosed);


}

void Application::InitStorages()
{
    rootConfig.Init(getConfig().path.configFolder, getConfig().path.configName); //-V807
    rootConfig.LoadOrCreate();

    rootLocalization.Init(getConfig().path.localizationFolder, getConfig().path.localizationName);
    rootLocalization.LoadOrCreate();
}

void Application::InitGameRelated()
{
    textureProvider.LoadResources();
    simulation.Init();

}

Simulation const& Application::GetSimulation()
{
    return GetInstance().simulation;
}

MenuLayer& Application::GetMenuLayer()
{
    return GetInstance().menuLayer;
}

GeneralLocalization const& Application::GetLoc()
{
    return GetInstance().rootLocalization.localization;
}

GeneralConfig const& Application::GetConfig()
{
    return GetInstance().rootConfig.configGeneral;
}


TextureProvider const& Application::GetTextureProvider()
{
    return GetInstance().textureProvider;
}

Random& Application::GetRandom()
{
    return GetInstance().random;
}

LevelProvider& Application::GetLevelProvider()
{
    return GetInstance().levelProvider;
}

void Application::Update()
{
    simulation.Update(1/59.f);
}

void Application::Draw()
{
    window.clear(sf::Color::Black);
    window.draw(simulation);
    window.display();
}

void Application::FinishWork()
{
    Log(getLoc().application.closed);

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

