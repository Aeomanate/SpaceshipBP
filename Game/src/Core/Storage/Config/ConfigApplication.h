#ifndef SPACESHIPBP_CONFIGAPPLICATION_H
#define SPACESHIPBP_CONFIGAPPLICATION_H

#include "SFML/Window/VideoMode.hpp"
#include "SFML/Window/WindowStyle.hpp"
#include "Utility/Serialization/Serializable.h"
#include "ConfigSimulation.h"
#include "Core/Storage/Localization/ApplicationLocalization.h"
#include "ConfigWindow.h"
#include "ConfigFile.h"
#include "ConfigLogs.h"

SERIALIZABLE_S(ConfigApplication, UserJsonConversions)
{
    ConfigConfig Config;
    ConfigLogs Logs;

    ConfigWindow window;
    ConfigSimulation Simulation;
};

#endif //SPACESHIPBP_CONFIGAPPLICATION_H
