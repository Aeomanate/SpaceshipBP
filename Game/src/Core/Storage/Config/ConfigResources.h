#ifndef SPACESHIPBP_CONFIGRESOURCES_H
#define SPACESHIPBP_CONFIGRESOURCES_H

#include "Utility/Serialization/Serializable.h"
#include "ConfigTextures.h"
#include "ConfigFonts.h"

SERI_S(ConfigResources)
{
    SERI_C(ConfigResources)

    SERI_COMPOSITE_V(ConfigTextures, textures);
    SERI_COMPOSITE_V(ConfigFonts, fonts);
};

#endif //SPACESHIPBP_CONFIGRESOURCES_H
