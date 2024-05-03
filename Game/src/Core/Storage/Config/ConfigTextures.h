#ifndef SPACESHIPBP_CONFIGTEXTURES_H
#define SPACESHIPBP_CONFIGTEXTURES_H

#include "Utility/Serialization/Serializable.h"
#include "ConfigTexture.h"

struct GameJsonConversions;

SERI_S(ConfigTextures)
{
    SERI_C(ConfigTextures)

    SERI_COMPOSITE_V_MEMBERS_INIT(
        ConfigTexture, asteroidBig,
        "AsteroidBig.png"s,
        ConfigTexture::FrameSizeT{128 o 128},
        ConfigTexture::FrameTotalT(48)
    );

    SERI_COMPOSITE_V_MEMBERS_INIT(
        ConfigTexture, asteroidSmall,
        "AsteroidSmall.png"s,
        ConfigTexture::FrameSizeT{85 o 100},
        ConfigTexture::FrameTotalT(30)
    );

    SERI_COMPOSITE_V_MEMBERS_INIT(
        ConfigTexture, background,
        "Background.jpg"s,
        ConfigTexture::FrameSizeT{1920 o 1080},
        ConfigTexture::FrameTotalT(1),
        ConfigTexture::OriginT(PositionInRectagle::UPPER_LEFT)
    );

    SERI_COMPOSITE_V_MEMBERS_INIT(
        ConfigTexture, player,
        "Player.png"s,
        ConfigTexture::FrameSizeT{64 o 64},
        ConfigTexture::FrameTotalT(1)
    );
    SERI_COMPOSITE_V_MEMBERS_INIT(
        ConfigTexture, beam,
        "Beam.png"s,
        ConfigTexture::FrameSizeT{10 o 40},
        ConfigTexture::FrameTotalT(8),
        ConfigTexture::OriginT(PositionInRectagle::CENTER),
        sf::Vector2i {-1 o 0}
    );

    SERI_COMPOSITE_V_MEMBERS_INIT(
        ConfigTexture, explosion1,
        "Explosion1.png"s,
        ConfigTexture::FrameSizeT {155 o 155},
        ConfigTexture::FrameTotalT(17)
    );
    SERI_COMPOSITE_V_MEMBERS_INIT(
        ConfigTexture, explosion2,
        "Explosion2.png"s,
        ConfigTexture::FrameSizeT {155 o 155},
        ConfigTexture::FrameTotalT(34)
    );
    SERI_COMPOSITE_V_MEMBERS_INIT(
        ConfigTexture, explosion3,
        "Explosion3.png"s,
        ConfigTexture::FrameSizeT {155 o 155},
        ConfigTexture::FrameTotalT(34)
    );
    SERI_COMPOSITE_V_MEMBERS_INIT(
        ConfigTexture, explosion4,
        "Explosion4.png"s,
        ConfigTexture::FrameSizeT {155 o 155},
        ConfigTexture::FrameTotalT(26)
    );

    SERI_COMPOSITE_V_MEMBERS_INIT(
        ConfigTexture, playerDeath,
        "PlayerDeath.png"s,
        ConfigTexture::FrameSizeT {300 o 300},
        ConfigTexture::FrameTotalT(21)
    );
};


#endif //SPACESHIPBP_CONFIGTEXTURES_H
