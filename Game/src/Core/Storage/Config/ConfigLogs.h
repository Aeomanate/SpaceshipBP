#ifndef SPACESHIPBP_CONFIGLOGS_H
#define SPACESHIPBP_CONFIGLOGS_H

#include <filesystem>
namespace fs = std::filesystem;

#include "Utility/Serialization/Serializable.h"
#include "Core/Storage/UserJsonConversions.h"

SERIALIZABLE_STRUCT(ConfigLogs)
{
    fs::path Folder = "../Artifacts";
    SERIALIZABLE_V(std::string, Name, "Log.log");
};

#endif //SPACESHIPBP_CONFIGLOGS_H
