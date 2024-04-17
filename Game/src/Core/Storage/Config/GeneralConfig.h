#ifndef SPACESHIPBP_GENERALCONFIG_H
#define SPACESHIPBP_GENERALCONFIG_H

#include "SFML/Window/VideoMode.hpp"
#include "SFML/Window/WindowStyle.hpp"
#include "Utility/Serialization/Serializable.h"
#include "ConfigSimulation.h"
#include "Core/Storage/Localization/GeneralLocalization.h"
#include "ConfigWindow.h"
#include "ConfigFile.h"
#include "ConfigLogs.h"

SERIALIZABLE_S(GeneralConfig, UserJsonConversions)
{
    ConfigConfig Config;
    ConfigLogs Logs;

    ConfigWindow window;
    ConfigSimulation Simulation;
};

#endif //SPACESHIPBP_GENERALCONFIG_H
