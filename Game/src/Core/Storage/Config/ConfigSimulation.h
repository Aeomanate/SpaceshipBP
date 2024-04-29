#ifndef SPACESHIPBP_CONFIGSIMULATION_H
#define SPACESHIPBP_CONFIGSIMULATION_H

#include "Utility/Serialization/Serializable.h"
#include "ConfigLevels.h"
#include "ConfigSimulationKeys.h"

struct GameJsonConversions;

SERI_S(ConfigSimulation)
{
    SERI_C(ConfigSimulation)

    SERI_COMPOSITE_V(ConfigLevels, configLevels);
    SERI_COMPOSITE_V(ConfigSimulationKeys, keys);
};
#endif //SPACESHIPBP_CONFIGSIMULATION_H
