#ifndef SPACESHIPBP_APPLICATIONSHORTCUTS_H
#define SPACESHIPBP_APPLICATIONSHORTCUTS_H

#include "Core/MenuManager/MenuManager.h"
#include "Simulation/Simulation.h"
#include "Core/Storage/Config/ConfigApplication.h"
#include "Core/Storage/Localization/ApplicationLocalization.h"

MenuManager& getMenuManager();
const Simulation& getSimulation();
const ConfigApplication& getConfig();
const ApplicationLocalization& getLoc(); // Get localization config

#endif //SPACESHIPBP_APPLICATIONSHORTCUTS_H
