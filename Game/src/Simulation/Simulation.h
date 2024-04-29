#ifndef SPACESHIPBP_SIMULATION_H
#define SPACESHIPBP_SIMULATION_H

#include <memory>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window/Event.hpp>
#include "Core/EventsHandling/ListenersEmitters.h"
#include "Utility/Updatable.h"
#include "Simulation/ECS/Levels/Level.h"

class Simulation: public Updatable, sf::Drawable
{
public:
    Simulation();
    void Init();

public:
    void Update(float dt) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public: // Emitters

public: // Public listeners
    DATA_LISTENER(KeyPressed, sf::Event::KeyEvent);
    DATA_LISTENER(MouseButtonClicked, sf::Event::MouseButtonEvent);

private: // Private listeners

private:
    Level* currentLevel;
};


#endif //SPACESHIPBP_SIMULATION_H
