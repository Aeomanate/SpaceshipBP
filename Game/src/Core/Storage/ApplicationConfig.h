#ifndef SPACESHIPBP_APPLICATIONCONFIG_H
#define SPACESHIPBP_APPLICATIONCONFIG_H

#include "SFML/Graphics.hpp"
#include "Utility/Serialization/Serializable.h"
#include "Core/Storage/Config/ConfigApplication.h"
#include "Core/Storage/Config/ConfigSimulation.h"
#include "Core/Storage/Localization/ApplicationLocalization.h"
#include "Utility/Logger/Logger.h"
#include "StorageRoot.h"

class ApplicationConfig: public StorageRoot
{
public:
    inline ApplicationConfig(): StorageRoot(&applicationConfig) { };
    ConfigApplication applicationConfig;
};


#endif //SPACESHIPBP_APPLICATIONCONFIG_H
