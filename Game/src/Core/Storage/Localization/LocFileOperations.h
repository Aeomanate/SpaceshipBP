#ifndef SPACESHIPBP_LOCFILEOPERATIONS_H
#define SPACESHIPBP_LOCFILEOPERATIONS_H

#include "Utility/Serialization/Serializable.h"
#include "Core/Storage/GameJsonConversions.h"

SERI_S(LocFileOperations)
{
    SERI_C(LocFileOperations)

    SERI_STR_V(absentNotify, "Absent file");
    SERI_STR_V(createNotify, "Creating absent file");
    SERI_STR_V(tryOpenOrCreateNotify, "Trying to open or create file");
    SERI_STR_V(openOrCreateFailedWarning, "Failed open or create file");
    SERI_STR_V(jsonParseWarning, "Parse failed");
    SERI_STR_V(jsonWriteWarning, "Saving failed");
    SERI_STR_V(textureOpenFailedWarning, "Texture open failed");
};


#endif //SPACESHIPBP_LOCFILEOPERATIONS_H
