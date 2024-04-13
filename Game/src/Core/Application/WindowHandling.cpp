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
    if (e.key.code == sf::Keyboard::Space || e.key.code == sf::Keyboard::Add)
    {

    }
    else if (e.key.code == sf::Keyboard::N || e.key.code == sf::Keyboard::Subtract)
    {

    }
}

void Application::handlePressedKeyMouse(const sf::Event& e)
{
    if (e.mouseButton.button == sf::Mouse::Button::Left)
    {

    }
    else if (e.mouseButton.button == sf::Mouse::Button::Right)
    {

    }
}

