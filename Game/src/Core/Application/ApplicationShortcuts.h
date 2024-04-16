#ifndef SPACESHIPBP_APPLICATIONSHORTCUTS_H
#define SPACESHIPBP_APPLICATIONSHORTCUTS_H

#include "Core/MenuManager/MenuManager.h"
#include "Simulation/Simulation.h"
#include "Core/Config/ConfigApplication.h"
#include "Core/Config/ConfigLocalization.h"

MenuManager& getMenuManager();
const Simulation& getSimulation();
const ConfigApplication& getConfig();
const ConfigLocalization& getLoc(); // Get localization config

#endif //SPACESHIPBP_APPLICATIONSHORTCUTS_H
