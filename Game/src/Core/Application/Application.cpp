#include "Application.h"
#include "ObjectsAggregator/GetterLog.h"
#include "ObjectsAggregator/GetterMenuLayer.h"

using namespace std::string_literals;

Application& Application::Init()
{
    Logger::GlobalLogLevel = Logger::Level::VERBOSE;

    Log("\n\n"s + *getLoc().application.started, "");

    InitListeners();
    InitStorages();
    InitGameRelated();

    ConfigWindow const& windowParams = getConfig().window;
    Setup(windowParams.videoMode, windowParams.name, windowParams.style);

    return *this;
}

void Application::InitListeners()
{
    listenerKeyPressed.SubscribeEmitter(emitterKey);
    listenerLastMenuClosed.SubscribeEmitter(getMenuLayer().emitterLastMenuClosed);


}

void Application::InitStorages()
{
    GetAggregatedObject<RootConfig>().Init(getConfig().path.configFolder, getConfig().path.configName); //-V807
    GetAggregatedObject<RootConfig>().LoadOrCreate();

    GetAggregatedObject<RootLocalization>().Init(getConfig().path.localizationFolder, getConfig().path.localizationName);
    GetAggregatedObject<RootLocalization>().LoadOrCreate();
}

void Application::InitGameRelated()
{
    GetAggregatedObject<TexturesCache>().LoadResources();
    GetAggregatedObject<Simulation>().Init();

}

void Application::Update()
{
    GetAggregatedObject<Simulation>().Update(1/59.f);
}

void Application::Draw()
{
    window.clear(sf::Color::Black);
    window.draw(GetAggregatedObject<Simulation>());
    window.display();
}

void Application::FinishWork()
{
    Log(getLoc().application.closed);

    GetAggregatedObject<RootConfig>().Save();
    GetAggregatedObject<RootLocalization>().Save();
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

