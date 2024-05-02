#ifndef SPACESHIPBP_CONFIGSIMULATION_H
#define SPACESHIPBP_CONFIGSIMULATION_H

#include "Utility/Serialization/Serializable.h"
#include "ConfigLevels.h"
#include "ConfigSimulationKeys.h"
#include "ConfigPlayer.h"

struct GameJsonConversions;

SERI_S(ConfigSimulation)
{
    SERI_C(ConfigSimulation)

    SERI_COMPOSITE_V(ConfigLevels, configLevels);
    SERI_COMPOSITE_V(ConfigSimulationKeys, keys);
    SERI_COMPOSITE_V(ConfigPlayer, player);
};
#endif //SPACESHIPBP_CONFIGSIMULATION_H
