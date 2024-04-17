#ifndef SPACESHIPBP_APPLICATIONCONFIG_H
#define SPACESHIPBP_APPLICATIONCONFIG_H

#include "SFML/Graphics.hpp"
#include "Utility/Serialization/Serializable.h"
#include "Core/Storage/Config/GeneralConfig.h"
#include "Core/Storage/Config/ConfigSimulation.h"
#include "Core/Storage/Localization/GeneralLocalization.h"
#include "Utility/Logger/Logger.h"
#include "StorageRoot.h"

class ApplicationConfig: public StorageRoot
{
public:
    inline ApplicationConfig(): StorageRoot(&configGeneral) { };
    GeneralConfig configGeneral;
};


#endif //SPACESHIPBP_APPLICATIONCONFIG_H
