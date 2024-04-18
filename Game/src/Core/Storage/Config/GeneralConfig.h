#ifndef SPACESHIPBP_GENERALCONFIG_H
#define SPACESHIPBP_GENERALCONFIG_H

#include "SFML/Window/VideoMode.hpp"
#include "SFML/Window/WindowStyle.hpp"
#include "Utility/Serialization/Serializable.h"
#include "ConfigSimulation.h"
#include "ConfigWindow.h"
#include "ConfigFile.h"
#include "ConfigLogs.h"

SERI_S(GeneralConfig)
{
    SERI_C(GeneralConfig)

    SERI_COMPOSITE_V(ConfigFile, config);
    SERI_COMPOSITE_V(ConfigLogs, logs);

    SERI_COMPOSITE_V(ConfigWindow, window);
    SERI_COMPOSITE_V(ConfigSimulation, simulation);
};

#endif //SPACESHIPBP_GENERALCONFIG_H
