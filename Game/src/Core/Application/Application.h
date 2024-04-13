#ifndef SPACESHIPBP_APPLICATION_H
#define SPACESHIPBP_APPLICATION_H

#include <unordered_map>
#include "SFML/Graphics.hpp"
#include "Utility/EventsHandling/ListenersEmitters.h"
#include "Utility/MenuManager/MenuManager.h"
#include "Simulation/Simulation.h"

class Application
{
public:
    explicit Application();

    void startLoop();

private: // Game-related methods

    void update();

    void draw();

private: // Emitters
    DATA_EMITTER(KeyEvent, sf::Event::KeyEvent);
    DATA_EMITTER(MouseClicked, sf::Event::MouseButtonEvent);

private: // Listeners
    SIMPLE_LISTENER(LastMenuClosed);

private: // Game-related objects
    MenuManager menuManager;
    Simulation simulation;

private: // Window-handling methods
    void handleInput();
    void initSfmlEventHandler();

    void handleProgramClose(const sf::Event&);
    void handlePressedKeyKeyboard(const sf::Event& e);
    void handlePressedKeyMouse(const sf::Event& e);

private:
    bool isApplicationWork = true;

    using WindowEventHandlerFunc = decltype(&Application::handleProgramClose);
    std::unordered_map<sf::Event::EventType, WindowEventHandlerFunc> sfmlEventHandlerMap;

    sf::RenderWindow window;
};

#endif
