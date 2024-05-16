#ifndef SPACESHIPBP_GENERALLOCALIZATION_H
#define SPACESHIPBP_GENERALLOCALIZATION_H

#include "Utility/Serialization/Serializable.h"
#include "LocLogLevel.h"
#include "LocFileOperations.h"
#include "LocApplication.h"
#include "LocSimulation.h"

SERI_S(GeneralLocalization)
{
    SERI_C(GeneralLocalization)

    SERI_COMPOSITE_V(LocLogLevel, logLevel);
    SERI_COMPOSITE_V(LocFileOperations, fileOperations);
    SERI_COMPOSITE_V(LocApplication, application);
    SERI_COMPOSITE_V(LocSimulation, simulation);
};




#endif //SPACESHIPBP_GENERALLOCALIZATION_H
