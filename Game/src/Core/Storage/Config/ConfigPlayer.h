#ifndef SPACESHIPBP_CONFIGPLAYER_H
#define SPACESHIPBP_CONFIGPLAYER_H

#include "Utility/Serialization/Serializable.h"
#include "SFML/Config.hpp"
#include "SFML/System/Vector2.hpp"
#include "Core/Storage/GameJsonConversions.h"

SERI_S(ConfigPlayer)
{
    SERI_C(ConfigPlayer)

    SERI_STR_V(imageName, "Player.png");
    SERI_V(float, mass, 2000);
    SERI_V(sf::Uint32, enginePowerMultipler, 30);
    SERI_V(sf::Uint32, slowdownPixPerSec, 100);
    SERI_V(sf::Vector2f, startPosition, 500 o 500);
};

#endif //SPACESHIPBP_CONFIGPLAYER_H
