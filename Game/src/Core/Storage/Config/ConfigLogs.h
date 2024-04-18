#ifndef SPACESHIPBP_CONFIGLOGS_H
#define SPACESHIPBP_CONFIGLOGS_H

#include <filesystem>
namespace fs = std::filesystem;

#include "Utility/Serialization/Serializable.h"
#include "Core/Storage/GameJsonConversions.h"

SERI_S(ConfigLogs)
{
    SERI_C(ConfigLogs)

    fs::path Folder = "../Artifacts/Logs";
    SERI_STR_V(name, "LogInternal.log");
};

#endif //SPACESHIPBP_CONFIGLOGS_H
