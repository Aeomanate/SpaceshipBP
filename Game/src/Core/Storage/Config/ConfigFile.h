#ifndef SPACESHIPBP_CONFIGFILE_H
#define SPACESHIPBP_CONFIGFILE_H

#include <filesystem>
namespace fs = std::filesystem;

#include "Utility/Serialization/Serializable.h"
#include "Core/Storage/UserJsonConversions.h"


SERIALIZABLE_STRUCT(ConfigConfig)
{
    fs::path folder = "../Artifacts";
    SERIALIZABLE_V(std::string, Name, "Config.Json");
};

#endif //SPACESHIPBP_CONFIGFILE_H
