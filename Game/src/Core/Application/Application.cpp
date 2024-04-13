#include "Application.h"


Application::Application()
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

Config const& Application::GetConfig()
{
    return GetInstance()->config;
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
