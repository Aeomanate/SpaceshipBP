#ifndef SPACESHIPBP_APPLICATIONSHORTCUTS_H
#define SPACESHIPBP_APPLICATIONSHORTCUTS_H

#include "Core/MenuManager/MenuManager.h"
#include "Simulation/Simulation.h"
#include "Core/Storage/Config/GeneralConfig.h"
#include "Core/Storage/Localization/GeneralLocalization.h"
#include "Utility/Math/Random/Random.h"

MenuManager& getMenuManager();
const Simulation& getSimulation();
const GeneralConfig& getConfig();
const GeneralLocalization& getLoc();
Random& getRnd();

#endif //SPACESHIPBP_APPLICATIONSHORTCUTS_H
