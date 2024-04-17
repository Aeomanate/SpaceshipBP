#ifndef SPACESHIPBP_APPLICATIONSHORTCUTS_H
#define SPACESHIPBP_APPLICATIONSHORTCUTS_H

#include "Core/MenuManager/MenuManager.h"
#include "Simulation/Simulation.h"
#include "Core/Storage/Config/GeneralConfig.h"
#include "Core/Storage/Localization/GeneralLocalization.h"

MenuManager& getMenuManager();
const Simulation& getSimulation();
const GeneralConfig& getConfig();
const GeneralLocalization& getLoc(); // Get localization config

#endif //SPACESHIPBP_APPLICATIONSHORTCUTS_H
