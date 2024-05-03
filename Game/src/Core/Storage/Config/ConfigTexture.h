#ifndef SPACESHIPBP_CONFIGTEXTURE_H
#define SPACESHIPBP_CONFIGTEXTURE_H

#include <array>
#include <SFML/Graphics.hpp>
#include "Utility/Serialization/Serializable.h"
#include "Utility/Visual/PositionInRectangle.h"

struct GameJsonConversions;


SERI_S(ConfigTexture)
{
    SERI_C(ConfigTexture)

    using FrameSizeT = sf::Vector2i;
    using FrameTotalT = sf::Uint32;
    using OriginT = PositionInRectagle;
    using OrientationT = sf::Vector2i;
    using FrameIntervalMsT = sf::Uint32;
    using RepeatsCountT = sf::Int32;

    SERI_STR_V(name         , "MustBeReplaced");
    SERI_V(FrameSizeT       , frameSizePx    , { }              );
    SERI_V(FrameTotalT      , framesTotal    , 0                );
    SERI_V(OriginT          , origin         , OriginT::CENTER  );
    SERI_V(OrientationT     , orientation    , 1 o 0            );
    SERI_V(FrameIntervalMsT , frameIntervalMs, 50               );
    SERI_V(RepeatsCountT    , repeatsCount   , -1               );
};

#endif //SPACESHIPBP_CONFIGTEXTURE_H
