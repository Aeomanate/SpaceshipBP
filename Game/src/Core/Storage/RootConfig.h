#ifndef SPACESHIPBP_ROOTCONFIG_H
#define SPACESHIPBP_ROOTCONFIG_H

#include "SFML/Graphics.hpp"
#include "Utility/Serialization/Serializable.h"
#include "Core/Storage/Config/GeneralConfig.h"
#include "Core/Storage/Config/ConfigSimulation.h"
#include "Core/Storage/Localization/GeneralLocalization.h"
#include "Utility/Logger/Logger.h"
#include "StorageRoot.h"

class RootConfig: public StorageRoot
{
public:
    inline RootConfig(): StorageRoot(&configGeneral) { };
    GeneralConfig configGeneral;
};


#endif //SPACESHIPBP_ROOTCONFIG_H
