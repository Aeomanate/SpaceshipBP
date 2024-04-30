#ifndef SPACESHIPBP_CONFIGLEVELS_H
#define SPACESHIPBP_CONFIGLEVELS_H
#include "Utility/Serialization/Serializable.h"
#include <SFML/System/Vector2.hpp>
#include "ConfigLevel.h"

using namespace std::string_literals;

struct GameJsonConversions;

SERI_S(ConfigLevels)
{
    SERI_C(ConfigLevels)

    // TODO Implement arrays of SeriVar and SeriStruct

    SERI_COMPOSITE_V_MEMBERS_INIT(
        ConfigLevel, level1,
        "First level"s, "Second level"s,
        sf::Vector2u { 300 o 300 }, 300, 60
    );

    SERI_COMPOSITE_V_MEMBERS_INIT(
        ConfigLevel, level2,
        "Second level"s, "Third level"s,
        sf::Vector2u { 600 o 600 }, 600, 60
    );

    SERI_COMPOSITE_V_MEMBERS_INIT(
        ConfigLevel, level3,
        "Third level"s, "LevelEnd"s,
        sf::Vector2u { 300 o 300 }, 300, 60
    );
};


#endif //SPACESHIPBP_CONFIGLEVELS_H
