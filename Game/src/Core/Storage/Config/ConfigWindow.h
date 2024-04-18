#ifndef SPACESHIPBP_CONFIGWINDOW_H
#define SPACESHIPBP_CONFIGWINDOW_H

#include <string>
#include "SFML/Window/VideoMode.hpp"
#include "SFML/Window/WindowStyle.hpp"
#include "Core/Storage/GameJsonConversions.h"
#include "Utility/Serialization/Serializable.h"


SERI_S(ConfigWindow)
{
    SERI_C(ConfigWindow)

    SERI_STR_V(name, "SpaceShip");
    SERI_V(sf::VideoMode, videoMode, 1920 o 1080);
    SERI_V(sf::Uint32, style, sf::Style::Fullscreen);
};

#endif //SPACESHIPBP_CONFIGWINDOW_H
