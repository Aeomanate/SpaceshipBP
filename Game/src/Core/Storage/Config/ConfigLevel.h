#ifndef SPACESHIPBP_CONFIGLEVEL_H
#define SPACESHIPBP_CONFIGLEVEL_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Config.hpp>
#include "Utility/Serialization/Serializable.h"


SERI_S(ConfigLevel)
{
    SERI_C(ConfigLevel)

    SERI_STR_V(name, "LevelBase name");
    SERI_STR_V(next, "LevelBase name next");

    SERI_V(sf::Vector2u, requiredPos, { });
    SERI_V(sf::Uint32, zoneRadius, 0);
    SERI_V(sf::Uint32, timeToCompleteSec, 0);
    SERI_V(sf::Vector2u, dimesions, {1920 o 1080});
};


#endif //SPACESHIPBP_CONFIGLEVEL_H
