#ifndef SPACESHIPBP_CONFIGLOCALIZATION_H
#define SPACESHIPBP_CONFIGLOCALIZATION_H

#include "Serializable.h"

struct ConfigLocalization: public Serializable
{
    void SaveTo(rapidjson::Value& value) override;
    void LoadFrom(const rapidjson::Value& value) override;

    std::string configNotFound = "Config not found, creating one with default parameters";
    std::string logOpenError = "Unable to create log file for out error";
};

#endif //SPACESHIPBP_CONFIGLOCALIZATION_H
