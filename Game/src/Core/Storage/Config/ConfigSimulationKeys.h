#ifndef SPACESHIPBP_CONFIGSIMULATIONKEYS_H
#define SPACESHIPBP_CONFIGSIMULATIONKEYS_H

#include "Utility/Serialization/Serializable.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>


SERI_S(ConfigSimulationKeys)
{
    SERI_C(ConfigSimulationKeys)

    SERI_V(sf::Keyboard::Key, up, sf::Keyboard::Key::W);
    SERI_V(sf::Keyboard::Key, down, sf::Keyboard::Key::S);
    SERI_V(sf::Keyboard::Key, left, sf::Keyboard::Key::A);
    SERI_V(sf::Keyboard::Key, right, sf::Keyboard::Key::D);
    SERI_V(int, fire, sf::Mouse::Button::Left);
};

#endif //SPACESHIPBP_CONFIGSIMULATIONKEYS_H
