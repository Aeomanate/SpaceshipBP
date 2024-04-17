#ifndef SPACESHIPBP_CONFIGWINDOW_H
#define SPACESHIPBP_CONFIGWINDOW_H

#include <string>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include "Core/UserJsonConversions.h"
#include "Utility/Serialization/Serializable.h"


struct ConfigWindow: public Serialization::SerializableStruct<UserJsonConversions>
{
    SERIALIZABLE(sf::VideoMode, videoMode, 1920 o 1080);
    SERIALIZABLE(std::string, name, "SpaceShip");
    SERIALIZABLE(sf::Uint32, style, sf::Style::Fullscreen);
};

#endif //SPACESHIPBP_CONFIGWINDOW_H
