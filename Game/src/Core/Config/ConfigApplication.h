#ifndef SPACESHIPBP_CONFIGAPPLICATION_H
#define SPACESHIPBP_CONFIGAPPLICATION_H

#include "Serializable.h"

struct ConfigApplication: public Serializable
{
    void SaveTo(rapidjson::Value& value) override;
    void LoadFrom(const rapidjson::Value& value) override;

    std::string configFolder = "../Config/res";
    std::string configName = "ProgramConfig.json";
    std::string logFolder = "..";

    sf::VideoMode videoMode = sf::VideoMode(800, 600);
    std::string windowName = "SpaceShip";
    sf::Uint32 style = sf::Style::Fullscreen;
};

#endif //SPACESHIPBP_CONFIGAPPLICATION_H
