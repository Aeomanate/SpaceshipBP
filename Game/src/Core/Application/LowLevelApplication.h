#ifndef SPACESHIPBP_LOWLEVELAPPLICATION_H
#define SPACESHIPBP_LOWLEVELAPPLICATION_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <Core/EventsHandling/ListenersEmitters.h>

class LowLevelApplication
{
public:
    virtual LowLevelApplication& Init() = 0;
    void Setup(sf::VideoMode videoMode, const std::string& applicationName, sf::Uint32 style = sf::Style::Fullscreen);
    void Run();

public: // Emitters
    DATA_EMITTER(Key, sf::Event::KeyEvent);
    DATA_EMITTER(KeyPressed, sf::Event::KeyEvent);
    DATA_EMITTER(KeyReleased, sf::Event::KeyEvent);
    DATA_EMITTER(MouseClicked, sf::Event::MouseButtonEvent);
    DATA_EMITTER(MouseMoved, sf::Vector2i);

protected: // Interface for derived class
    virtual void Draw() = 0;
    virtual void Update() = 0;
    virtual void FinishWork() = 0;

protected:
    bool isLowLevelApplicationWork = true;
    sf::RenderWindow window;

private: // Window-handling methods
    void initSfmlEventHandler();
    void HandleInput();

    void handleProgramClose(const sf::Event&);
    void handlePressedKeyKeyboard(const sf::Event& e);
    void handleReleasedKeyKeyboard(const sf::Event& e);
    void handlePressedKeyMouse(const sf::Event& e);

    void handleMouseMoving();

private:
    using WindowEventHandlerFunc = decltype(&LowLevelApplication::handleProgramClose);
    std::unordered_map<sf::Event::EventType, WindowEventHandlerFunc> sfmlEventHandlerMap;

    std::unordered_map<sf::Keyboard::Key, bool> keysStates;
    sf::Vector2i mousePosition = { };
};


#endif //SPACESHIPBP_LOWLEVELAPPLICATION_H
