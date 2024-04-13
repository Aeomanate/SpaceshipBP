#include "LowLevelApplication.h"
#include <Windows.h>

void LowLevelApplication::Setup(sf::VideoMode videoMode, const std::string& applicationName)
{
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
    window.create(videoMode, applicationName);
    initSfmlEventHandler();
}

void LowLevelApplication::Run()
{
    while(isLowLevelApplicationWork)
    {
        Draw();
        HandleInput();
        Update();

    }
}

void LowLevelApplication::HandleInput()
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


void LowLevelApplication::initSfmlEventHandler()
{
    sfmlEventHandlerMap[sf::Event::EventType::Closed] = &LowLevelApplication::handleProgramClose;
    sfmlEventHandlerMap[sf::Event::EventType::KeyPressed] = &LowLevelApplication::handlePressedKeyKeyboard;
    sfmlEventHandlerMap[sf::Event::EventType::MouseButtonPressed] = &LowLevelApplication::handlePressedKeyMouse;
}

void LowLevelApplication::handleProgramClose(const sf::Event&)
{
    isLowLevelApplicationWork = false;
}

void LowLevelApplication::handlePressedKeyKeyboard(const sf::Event& e)
{
    emitterKeyEvent.Emit(e.key);
}

void LowLevelApplication::handlePressedKeyMouse(const sf::Event& e)
{
    emitterMouseClicked.Emit(e.mouseButton);
}
