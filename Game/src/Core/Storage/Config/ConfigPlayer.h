#ifndef SPACESHIPBP_CONFIGPLAYER_H
#define SPACESHIPBP_CONFIGPLAYER_H

#include "Utility/Serialization/Serializable.h"
#include "SFML/Config.hpp"

struct GameJsonConversions;
SERI_S(ConfigPlayer)
{
    SERI_C(ConfigPlayer)

    SERI_V(sf::Uint32, mass, 2000);
    SERI_V(sf::Uint32, enginePowerMultipler, 30);
    SERI_V(sf::Uint32, slowdownPixPerSec, 100);
};

#endif //SPACESHIPBP_CONFIGPLAYER_H
