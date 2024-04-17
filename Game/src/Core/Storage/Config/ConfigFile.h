#ifndef SPACESHIPBP_CONFIGFILE_H
#define SPACESHIPBP_CONFIGFILE_H

#include "Utility/Serialization/Serializable.h"

#include <filesystem>
namespace fs = std::filesystem;

struct ConfigConfig
{
    fs::path Folder = "../Artifacts";
    std::string Name = "Config.Json";
};

#endif //SPACESHIPBP_CONFIGFILE_H
