#include "Application.h"


Application::Application()
: listenerLastMenuClosed([this] { OnLastMenuClosed(); })
{
    window.create({800, 600}, "Space ship");
    initSfmlEventHandler();

    listenerLastMenuClosed.SubscribeEmitter(menuManager.emitterLastMenuClosed);
}

void Application::startLoop()
{
    while (isApplicationWork)
    {
        draw();
        handleInput();
        update();
    }
}

void Application::update()
{

}

void Application::draw()
{
    window.clear(sf::Color::Black);
    window.display();
}

