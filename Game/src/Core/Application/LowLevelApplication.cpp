#include "LowLevelApplication.h"
#include "Utility/SystemRelated/SystemRelated.h"
#include <Windows.h>

void LowLevelApplication::Setup(sf::VideoMode videoMode, const std::string& applicationName, sf::Uint32 style)
{
    SystemRelated::HideConsole();
    window.create(videoMode, applicationName, style);
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

    FinishWork();
}

void LowLevelApplication::HandleInput()
{
    sf::Event e{ };
    while (window.pollEvent(e))
    {
        auto it = sfmlEventHandlerMap.find(e.type);
        if (it == sfmlEventHandlerMap.end())
        { continue; }

        (this->*it->second)(e);
    }

    handleMouseMoving();
}


void LowLevelApplication::initSfmlEventHandler()
{
    sfmlEventHandlerMap[sf::Event::EventType::Closed] = &LowLevelApplication::handleProgramClose;
    sfmlEventHandlerMap[sf::Event::EventType::KeyPressed] = &LowLevelApplication::handlePressedKeyKeyboard;
    sfmlEventHandlerMap[sf::Event::EventType::KeyReleased] = &LowLevelApplication::handleReleasedKeyKeyboard;
    sfmlEventHandlerMap[sf::Event::EventType::MouseButtonPressed] = &LowLevelApplication::handlePressedKeyMouse;
}

void LowLevelApplication::handleProgramClose(const sf::Event&)
{
    isLowLevelApplicationWork = false;
}

void LowLevelApplication::handlePressedKeyKeyboard(const sf::Event& e)
{
    emitterKey.Emit(e.key);

    auto it = keysStates.find(e.key.code);
    if(it != keysStates.end() && it->second)
    { return; }

    keysStates.insert_or_assign(e.key.code, true);
    emitterKeyPressed.Emit(e.key);
}

void LowLevelApplication::handleReleasedKeyKeyboard(const sf::Event& e)
{
    keysStates.insert_or_assign(e.key.code, false);
    emitterKeyReleased.Emit(e.key);
}

void LowLevelApplication::handlePressedKeyMouse(const sf::Event& e)
{
    emitterMouseClicked.Emit(e.mouseButton);
}

void LowLevelApplication::handleMouseMoving()
{
    sf::Vector2i newMousePos = sf::Mouse::getPosition(window);
    if(mousePosition != newMousePos)
    {
        mousePosition = newMousePos;
        emitterMouseMoved.Emit(mousePosition);
    }
}
