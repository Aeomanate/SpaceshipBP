#ifndef SPACESHIPBP_CONFIGAPPLICATION_H
#define SPACESHIPBP_CONFIGAPPLICATION_H

#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include "Utility/Serialization/Serializable.h"
#include "ConfigSimulation.h"
#include "ConfigLocalization.h"
#include "ConfigWindow.h"
#include "ConfigFile.h"
#include "ConfigLogs.h"

struct ConfigApplication: public Serialization::SerializableStruct
{
    ConfigConfig Config;
    ConfigLogs Logs;

    ConfigWindow window;
    ConfigSimulation Simulation;
    ConfigLocalization localization;
};

#endif //SPACESHIPBP_CONFIGAPPLICATION_H
