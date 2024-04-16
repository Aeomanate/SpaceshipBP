#ifndef SPACESHIPBP_CONFIGWINDOW_H
#define SPACESHIPBP_CONFIGWINDOW_H

#include <rapidjson/document.h>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include "Utility/Serialization/Serializable.h"
#include <string>


struct ConfigWindow: public SerializableStruct
{
    // SerializableVariable<sf::VideoMode> videoMode = { "videoMode", sf::VideoMode(1920, 1080)};
    sf::VideoMode videoMode = sf::VideoMode(1920, 1080);

    // SerializableVariable<std::string> name = { "name", "SpaceShip" };
    std::string name = { "name", "SpaceShip" };

    // SerializableVariable<sf::Uint32> style = { "style", sf::Uint32(sf::Style::Fullscreen) };
    sf::Uint32 style = sf::Style::Fullscreen;
};

#endif //SPACESHIPBP_CONFIGWINDOW_H
