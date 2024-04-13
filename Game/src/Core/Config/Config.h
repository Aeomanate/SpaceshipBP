#ifndef SPACESHIPBP_CONFIG_H
#define SPACESHIPBP_CONFIG_H

#include "SFML/Graphics.hpp"
#include "Serializable.h"
#include "ConfigApplication.h"
#include "ConfigSimulation.h"
#include "ConfigLocalization.h"

class Config
{
public:
    void Load();
    void Store();
    void CheckStoredAndLoad();

    ConfigApplication application;
    ConfigSimulation simulation;
    ConfigLocalization localization;

    Serializable* configs {
        &application
    };
};


#endif //SPACESHIPBP_CONFIG_H
