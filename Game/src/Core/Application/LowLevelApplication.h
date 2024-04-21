#ifndef SPACESHIPBP_LOWLEVELAPPLICATION_H
#define SPACESHIPBP_LOWLEVELAPPLICATION_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <Core/EventsHandling/ListenersEmitters.h>

class LowLevelApplication
{
public:
    virtual void Init() = 0;
    void Setup(sf::VideoMode videoMode, const std::string& applicationName, sf::Uint32 style = sf::Style::Fullscreen);
    void Run();

protected: // Emitters
    DATA_EMITTER(KeyEvent, sf::Event::KeyEvent);
    DATA_EMITTER(MouseClicked, sf::Event::MouseButtonEvent);

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
    void handlePressedKeyMouse(const sf::Event& e);

private:
    using WindowEventHandlerFunc = decltype(&LowLevelApplication::handleProgramClose);
    std::unordered_map<sf::Event::EventType, WindowEventHandlerFunc> sfmlEventHandlerMap;
};


#endif //SPACESHIPBP_LOWLEVELAPPLICATION_H
