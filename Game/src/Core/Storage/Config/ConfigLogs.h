#ifndef SPACESHIPBP_CONFIGLOGS_H
#define SPACESHIPBP_CONFIGLOGS_H

#include "Utility/Serialization/Serializable.h"
#include <filesystem>
namespace fs = std::filesystem;

struct ConfigLogs
{
    fs::path Folder = "../Artifacts";
    std::string Name = "Log.log";
};

#endif //SPACESHIPBP_CONFIGLOGS_H
