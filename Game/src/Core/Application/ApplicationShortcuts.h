#ifndef SPACESHIPBP_APPLICATIONSHORTCUTS_H
#define SPACESHIPBP_APPLICATIONSHORTCUTS_H

#include "Core/GameLayers/MenuLayer.h"
#include "Simulation/Simulation.h"
#include "Core/Storage/Config/GeneralConfig.h"
#include "Core/Storage/Localization/GeneralLocalization.h"
#include "Utility/Math/Random/Random.h"
#include "Utility/Visual/TextureProvider.h"
#include "Simulation/Levels/LevelProvider.h"

MenuLayer& getMenuLayer();
const Simulation& getSimulation();
const GeneralConfig& getConfig();
const GeneralLocalization& getLoc();
const TextureProvider& getTextureProvider();
LevelProvider& getLevelProvider();
Random& getRnd();

#endif //SPACESHIPBP_APPLICATIONSHORTCUTS_H
