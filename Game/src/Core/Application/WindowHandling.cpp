#include "Application.h"

void Application::handleInput()
{
    sf::Event e{ };
    while (window.pollEvent(e))
    {
        if (sfmlEventHandlerMap.find(e.type) == sfmlEventHandlerMap.end())
        {
            continue;
        }

        (this->*sfmlEventHandlerMap[e.type])(e);
    }
}

void Application::initSfmlEventHandler()
{
    sfmlEventHandlerMap[sf::Event::EventType::Closed] = &Application::handleProgramClose;
    sfmlEventHandlerMap[sf::Event::EventType::KeyPressed] = &Application::handlePressedKeyKeyboard;
    sfmlEventHandlerMap[sf::Event::EventType::MouseButtonPressed] = &Application::handlePressedKeyMouse;
}

void Application::handleProgramClose(const sf::Event&)
{
    isApplicationWork = false;
}

void Application::handlePressedKeyKeyboard(const sf::Event& e)
{
    emitterKeyEvent.Emit(e.key);
}

void Application::handlePressedKeyMouse(const sf::Event& e)
{
    emitterMouseClicked.Emit(e.mouseButton);
}

