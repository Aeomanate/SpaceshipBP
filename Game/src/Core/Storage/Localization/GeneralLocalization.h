#ifndef SPACESHIPBP_GENERALLOCALIZATION_H
#define SPACESHIPBP_GENERALLOCALIZATION_H

#include <rapidjson/document.h>
#include "Utility/Serialization/Serializable.h"
#include "LocLogLevel.h"
#include "LocFileOperations.h"
#include "Core/Storage/GameJsonConversions.h"
#include <string>

SERI_S(GeneralLocalization)
{
    SERI_C(GeneralLocalization)

    SERI_COMPOSITE_V(LocLogLevel, logLevel);
    SERI_COMPOSITE_V(LocFileOperations, fileOperations);
};




#endif //SPACESHIPBP_GENERALLOCALIZATION_H
