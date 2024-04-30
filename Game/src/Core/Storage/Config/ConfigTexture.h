#ifndef SPACESHIPBP_CONFIGTEXTURE_H
#define SPACESHIPBP_CONFIGTEXTURE_H

#include <SFML/Graphics.hpp>
#include <array>
#include "Utility/Serialization/Serializable.h"

struct GameJsonConversions;

SERI_S(ConfigTexture)
{
    SERI_C(ConfigTexture)

    SERI_STR_V(name, "MustBeReplaced");
    SERI_V(sf::Vector2u, frameSizePx, sf::Vector2u());
    SERI_V(sf::Uint32, framesTotal, 0);
    SERI_V(sf::Vector2i, orientation, sf::Vector2u(1 o 0));
    SERI_V(sf::Uint32, frameIntervalMs, 50);
    SERI_V(sf::Int32, repeatsCount, -1);
};

#endif //SPACESHIPBP_CONFIGTEXTURE_H
