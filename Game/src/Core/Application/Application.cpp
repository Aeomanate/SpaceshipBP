#include "Application.h"


Application::Application()
{
    listenerLastMenuClosed.SubscribeEmitter(menuManager.emitterLastMenuClosed);

    simulation.listenerKeyPressed.SubscribeEmitter(emitterKeyEvent);
    simulation.listenerMouseButtonClicked.SubscribeEmitter(emitterMouseClicked);
}

void Application::Update()
{

}

void Application::Draw()
{
    window.clear(sf::Color::Black);
    window.display();
}

Simulation const& Application::GetSimulation() const
{
    return simulation;
}

MenuManager& Application::GetMenuManager()
{
    return menuManager;
}

