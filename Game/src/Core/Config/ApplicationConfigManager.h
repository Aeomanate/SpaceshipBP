#ifndef SPACESHIPBP_APPLICATIONCONFIGMANAGER_H
#define SPACESHIPBP_APPLICATIONCONFIGMANAGER_H

#include <SFML/Graphics.hpp>
#include "Utility/Serialization/Serializable.h"
#include "ConfigApplication.h"
#include "ConfigSimulation.h"
#include "ConfigLocalization.h"
#include "Utility/Logger/Logger.h"

class ApplicationConfigManager
{
public:
    ~ApplicationConfigManager();
    void LoadOrCreate();
    bool Load();
    void Save();

    ConfigApplication Application;
};


#endif //SPACESHIPBP_APPLICATIONCONFIGMANAGER_H
