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
    SERI_V(sf::Vector2u, frameSize, sf::Vector2u());
    SERI_V(uint32_t, frameCount, 0);
};

#endif //SPACESHIPBP_CONFIGTEXTURE_H
