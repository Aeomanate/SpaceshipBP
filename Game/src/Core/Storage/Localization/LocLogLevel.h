#ifndef SPACESHIPBP_LOCLOGLEVEL_H
#define SPACESHIPBP_LOCLOGLEVEL_H

#include "Utility/Serialization/Serializable.h"
#include "Core/Storage/UserJsonConversions.h"

SERIALIZABLE_STRUCT(LocLogLevel)
{
    SERIALIZABLE_LOC(verbose, "Verbose");
    SERIALIZABLE_LOC(notify, "Notify");
    SERIALIZABLE_LOC(warning, "Warning");
    SERIALIZABLE_LOC(error, "Error");
    SERIALIZABLE_LOC(fatalError, "Fatal Error");
};


#endif //SPACESHIPBP_LOCLOGLEVEL_H
