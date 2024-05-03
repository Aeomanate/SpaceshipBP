#ifndef SPACESHIPBP_LOCSIMULATION_H
#define SPACESHIPBP_LOCSIMULATION_H

#include <rapidjson/document.h>
#include "Utility/Serialization/Serializable.h"
#include "LocLogLevel.h"
#include "LocFileOperations.h"
#include "LocApplication.h"
#include "Core/Storage/GameJsonConversions.h"
#include <string>

SERI_S(LocSimulation)
{
    SERI_C(LocSimulation)

    SERI_STR_V(levelLoadingNotify, "LevelBase is loading");
    SERI_STR_V(levelLoadingSuccessfulNotify, "LevelBase loading completed");
    SERI_STR_V(levelLoadingFailedWarning, "LevelBase loading failed");


};

#endif //SPACESHIPBP_LOCSIMULATION_H
