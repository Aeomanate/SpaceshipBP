#ifndef SPACESHIPBP_SIMULATION_H
#define SPACESHIPBP_SIMULATION_H

#include <memory>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window/Event.hpp>
#include "Core/EventsHandling/ListenersEmitters.h"
#include "Utility/Updatable.h"
#include "SFML/System/Clock.hpp"

class LevelBase;

class Simulation: public Updatable, public sf::Drawable
{
public:
    Simulation();
    void Init();

    void Update(float dt) override;

public:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private: // listeners
    DATA_LISTENER(KeyPressed, sf::Event::KeyEvent);
    DATA_LISTENER(KeyReleased, sf::Event::KeyEvent);
    DATA_LISTENER(MouseButtonClicked, sf::Event::MouseButtonEvent);
    DATA_LISTENER(MouseMoved, sf::Vector2i);

private:


private:
    LevelBase* currentLevel = nullptr;
    std::unordered_map<sf::Keyboard::Key, sf::Vector2f> moveVectors;
    sf::Clock clockRealtime;
};


#endif //SPACESHIPBP_SIMULATION_H
