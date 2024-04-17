#ifndef SPACESHIPBP_LOCFILEOPERATIONS_H
#define SPACESHIPBP_LOCFILEOPERATIONS_H

#include "Utility/Serialization/Serializable.h"
#include "Core/Storage/UserJsonConversions.h"

SERIALIZABLE_STRUCT(LocFileOperations)
{
    SERIALIZABLE_LOC(absentNotify, "Absent file");
    SERIALIZABLE_LOC(createNotify, "Creating absent file");
    SERIALIZABLE_LOC(createFailed, "Failed creating file");
};


#endif //SPACESHIPBP_LOCFILEOPERATIONS_H
