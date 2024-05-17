#ifndef SPACESHIPBP_LOCAPPLICATION_H
#define SPACESHIPBP_LOCAPPLICATION_H

#include "Utility/Serialization/Serializable.h"
#include <string>


SERI_S(LocApplication)
{
    SERI_C(LocApplication)

    SERI_STR_V(started, "Application initialization...");
    SERI_STR_V(closed, "Application closing...");
    SERI_STR_V(nullPointerAccess, "Access to a null pointer");
};

#endif //SPACESHIPBP_LOCAPPLICATION_H
