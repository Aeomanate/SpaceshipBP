#ifndef SPACESHIPBP_CONFIGLEVELS_H
#define SPACESHIPBP_CONFIGLEVELS_H
#include "Utility/Serialization/Serializable.h"
#include <SFML/System/Vector2.hpp>
#include "ConfigLevel.h"


using namespace std::string_literals;


SERI_S(ConfigLevels)
{
    SERI_C(ConfigLevels)

    // TODO Implement arrays of SeriVar and SeriStruct

    SERI_COMPOSITE_V_MEMBERS_INIT(
        ConfigLevel, level1,
        "First level"s, "Second level"s,
        sf::Vector2u { 960 o 540 }, 600, 30
    );

    SERI_COMPOSITE_V_MEMBERS_INIT(
        ConfigLevel, level2,
        "Second level"s, "Third level"s,
        sf::Vector2u { 960-300 o 540 }, 300, 60
    );

    SERI_COMPOSITE_V_MEMBERS_INIT(
        ConfigLevel, level3,
        "Third level"s, "LevelEnd"s,
        sf::Vector2u { 960 o 540+150 }, 150, 120
    );
};


#endif //SPACESHIPBP_CONFIGLEVELS_H
