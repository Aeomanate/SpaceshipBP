#ifndef SPACESHIPBP_POSITIONINRECTANGLE_H
#define SPACESHIPBP_POSITIONINRECTANGLE_H

#include <cstdint>
#include <better_enums/enum.h>

BETTER_ENUM( //-V835
    PositionInRectagle, std::uint8_t,
    UPPER_LEFT  , UPPER_CENTER   , UPPER_RIGHT  ,
    CENTER_LEFT , CENTER         , CENTER_RIGHT ,
    BOTTOM_LEFT , BOTTOM         , BOTTOM_RIGHT  );

#endif //SPACESHIPBP_POSITIONINRECTANGLE_H
