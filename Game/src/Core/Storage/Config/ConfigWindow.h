#ifndef SPACESHIPBP_CONFIGWINDOW_H
#define SPACESHIPBP_CONFIGWINDOW_H

#include <string>
#include "SFML/Window/VideoMode.hpp"
#include "SFML/Window/WindowStyle.hpp"
#include "Core/Storage/UserJsonConversions.h"
#include "Utility/Serialization/Serializable.h"


SERIALIZABLE_STRUCT(ConfigWindow)
{
    SERIALIZABLE_V(sf::VideoMode, videoMode, 1920 o 1080);
    SERIALIZABLE_V(std::string, name, "SpaceShip");
    SERIALIZABLE_V(sf::Uint32, style, sf::Style::Fullscreen);
};

#endif //SPACESHIPBP_CONFIGWINDOW_H
