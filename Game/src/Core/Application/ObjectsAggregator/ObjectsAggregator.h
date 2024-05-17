#ifndef SPACESHIPBP_OBJECTSAGGREGATOR_H
#define SPACESHIPBP_OBJECTSAGGREGATOR_H

#include <tuple>
#include "Core/GameLayers/MenuLayer.h"
#include "Simulation/Simulation.h"
#include "Utility/Math/Random.h"
#include "Utility/Visual/TexturesCache.h"
#include "Utility/Visual/FontProvider.h"
#include "Simulation/GameLevels/Base/LevelProvider.h"
#include "Core/Storage/RootConfig.h"
#include "Core/Storage/RootLocalization.h"

template <class ApplicationT>
struct ObjectsAggregator
{
    std::tuple<
        MenuLayer,
        Simulation,
        Random,

        TexturesCache,
        FontsCache,
        LevelProvider,

        RootConfig,
        RootLocalization
    > applicationObjects;
};


#endif //SPACESHIPBP_OBJECTSAGGREGATOR_H
