#ifndef SPACESHIPBP_CONFIGFONT_H
#define SPACESHIPBP_CONFIGFONT_H

#include "Utility/Serialization/Serializable.h"


SERI_S(ConfigFont)
{
    SERI_C(ConfigFont);

    fs::path texturesFolder = "../res/fonts";
    SERI_STR_V(name, "FontNameStub");
};

#endif //SPACESHIPBP_CONFIGFONT_H
