#ifndef SPACESHIPBP_LOCLOGLEVEL_H
#define SPACESHIPBP_LOCLOGLEVEL_H

#include "Utility/Serialization/Serializable.h"
#include "Core/Storage/GameJsonConversions.h"

SERI_S(LocLogLevel)
{
    SERI_C(LocLogLevel)

    SERI_STR_V(verbose, "V");
    SERI_STR_V(notify, "N");
    SERI_STR_V(warning, "W");
    SERI_STR_V(error, "E");
    SERI_STR_V(fatalError, "FE");
};


#endif //SPACESHIPBP_LOCLOGLEVEL_H
