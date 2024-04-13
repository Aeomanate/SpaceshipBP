#ifndef SPACESHIPBP_CONFIGAPPLICATION_H
#define SPACESHIPBP_CONFIGAPPLICATION_H

#include "Serializable.h"
#include "SFML/Window/VideoMode.hpp"
#include "SFML/Window/WindowStyle.hpp"
#include <string>

struct ConfigApplication: public Serializable
{
    void SaveTo(rapidjson::Value& value) override;
    void LoadFrom(const rapidjson::Value& value) override;

    std::string configFolder = "../Config/res";
    std::string configName = "ProgramConfig.json";
    std::string logFolder = "..";

    sf::VideoMode videoMode = sf::VideoMode(1920, 1080);
    std::string windowName = "SpaceShip";
    sf::Uint32 style = sf::Style::Fullscreen;
};

#endif //SPACESHIPBP_CONFIGAPPLICATION_H
