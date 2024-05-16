#ifndef SPACESHIPBP_CONFIGFONTS_H
#define SPACESHIPBP_CONFIGFONTS_H

#include "Utility/Serialization/Serializable.h"
#include "ConfigFont.h"

SERI_S(ConfigFonts)
{
    SERI_C(ConfigFonts)

    SERI_COMPOSITE_V_MEMBERS_INIT(
        ConfigFont, basicFont,
        "BlizzardDOTRusbyme.otf"s
    );
};
#endif //SPACESHIPBP_CONFIGFONTS_H
