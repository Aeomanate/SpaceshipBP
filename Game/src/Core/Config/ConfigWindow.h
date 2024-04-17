#ifndef SPACESHIPBP_CONFIGWINDOW_H
#define SPACESHIPBP_CONFIGWINDOW_H

#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include "Utility/Serialization/Serializable.h"
#include "Core/UserJsonConversions.h"
#include <string>


struct ConfigWindow: public Serialization::SerializableStruct
{
    Serialization::SerializableVariable<sf::VideoMode, UserJsonConversions> videoMode = { "videoMode", sf::VideoMode(1920, 1080)};
    // sf::VideoMode videoMode = sf::VideoMode(1920, 1080);

    Serialization::SerializableVariable<std::string, UserJsonConversions> name = { "name", "SpaceShip" };
    // std::string name = { "name", "SpaceShip" };

    Serialization::SerializableVariable<sf::Uint32, UserJsonConversions> style = { "style", sf::Uint32(sf::Style::Fullscreen) };
    // sf::Uint32 style = sf::Style::Fullscreen;

};

#endif //SPACESHIPBP_CONFIGWINDOW_H
