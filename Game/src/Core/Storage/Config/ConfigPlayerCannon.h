#ifndef SPACESHIPBP_CONFIGPLAYERCANNON_H
#define SPACESHIPBP_CONFIGPLAYERCANNON_H

#include "Utility/Serialization/Serializable.h"
#include "SFML/Config.hpp"

SERI_S(ConfigPlayerCannon)
{
    SERI_C(ConfigPlayerCannon)

    SERI_V(sf::Uint32, cooldownMs, 2000);
    SERI_V(sf::Uint32, projectileSpeedPixPerSec, 300); // TODO Implement coordinate space for world
    SERI_V(sf::Uint32, projectileMass, 2000);

};

#endif //SPACESHIPBP_CONFIGPLAYERCANNON_H
