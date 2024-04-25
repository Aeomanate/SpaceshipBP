#ifndef SPACESHIPBP_CONFIGLEVELS_H
#define SPACESHIPBP_CONFIGLEVELS_H
#include "Utility/Serialization/Serializable.h"
#include "SFML/System/Vector2.hpp"
#include "ConfigLevel.h"

struct GameJsonConversions;

SERI_S(ConfigLevels)
{
    SERI_C(ConfigLevels)

    // TODO Implement arrays of SeriVar and SeriStruct

    SERI_COMPOSITE_V_MEMBERS_INIT(
        ConfigLevel, level1,
        "First level", "Second level",
        sf::Vector2u { 300 o 300 }, 300, 60
    );

    SERI_COMPOSITE_V_MEMBERS_INIT(
        ConfigLevel, level2,
        "Second level", "Third level",
        sf::Vector2u { 600 o 600 }, 600, 60
    );

    SERI_COMPOSITE_V_MEMBERS_INIT(
        ConfigLevel, level3,
        "Third level", "LevelEnd",
        sf::Vector2u { 300 o 300 }, 300, 60
    );
};


#endif //SPACESHIPBP_CONFIGLEVELS_H
