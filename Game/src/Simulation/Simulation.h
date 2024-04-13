#ifndef SPACESHIPBP_SIMULATION_H
#define SPACESHIPBP_SIMULATION_H

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include "Core/EventsHandling/ListenersEmitters.h"
#include "SFML/Window/Event.hpp"

class Simulation
{
public:
    Simulation();

public: // Emitters

public: // Public listeners
    DATA_LISTENER(KeyPressed, sf::Event::KeyEvent);
    DATA_LISTENER(MouseButtonClicked, sf::Event::MouseButtonEvent);

private: // Private listeners

private:

};


#endif //SPACESHIPBP_SIMULATION_H
