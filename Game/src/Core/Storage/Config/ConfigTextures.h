#ifndef SPACESHIPBP_CONFIGTEXTURES_H
#define SPACESHIPBP_CONFIGTEXTURES_H

#include "Utility/Serialization/Serializable.h"
#include "ConfigTexture.h"
using namespace std::string_literals;

struct GameJsonConversions;

SERI_S(ConfigTextures)
{
    SERI_C(ConfigTextures)

    SERI_COMPOSITE_V_MEMBERS_INIT(
        ConfigTexture, asteroidBig,
        "AsteroidBig.png"s,
        sf::Vector2u{128 o 128},
        48
    );

    SERI_COMPOSITE_V_MEMBERS_INIT(
        ConfigTexture, asteroidSmall,
        "AsteroidSmall.png"s,
        sf::Vector2u {85 o 100},
        30
    );

    SERI_COMPOSITE_V_MEMBERS_INIT(
        ConfigTexture, background,
        "background.png"s,
        sf::Vector2u {1920 , 1080},
        1
    );

    SERI_COMPOSITE_V_MEMBERS_INIT(
        ConfigTexture, player,
        "Player.png"s,
        sf::Vector2u {64 o 64},
        1
    );
    SERI_COMPOSITE_V_MEMBERS_INIT(
        ConfigTexture, beam,
        "Beam.png"s,
        sf::Vector2u {10 o 40},
        8
    );

    SERI_COMPOSITE_V_MEMBERS_INIT(
        ConfigTexture, explosion1,
        "Explosion1.png"s,
        sf::Vector2u {155 o 155},
        17
    );
    SERI_COMPOSITE_V_MEMBERS_INIT(
        ConfigTexture, explosion2,
        "Explosion2.png"s,
        sf::Vector2u {155 o 155},
        34
    );
    SERI_COMPOSITE_V_MEMBERS_INIT(
        ConfigTexture, explosion3,
        "Explosion3.png"s,
        sf::Vector2u {155 o 155},
        34
    );
    SERI_COMPOSITE_V_MEMBERS_INIT(
        ConfigTexture, explosion4,
        "Explosion4.png"s,
        sf::Vector2u {155 o 155},
        26
    );

    SERI_COMPOSITE_V_MEMBERS_INIT(
        ConfigTexture, playerDeath,
        "PlayerDeath.png"s,
        sf::Vector2u {300 o 300},
        21
    );
};


#endif //SPACESHIPBP_CONFIGTEXTURES_H
