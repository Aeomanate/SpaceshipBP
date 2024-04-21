#ifndef SPACESHIPBP_CONFIGPATH_H
#define SPACESHIPBP_CONFIGPATH_H

#include <filesystem>
namespace fs = std::filesystem;

#include "Utility/Serialization/Serializable.h"
#include "Core/Storage/GameJsonConversions.h"
#include "ConfigTextures.h"


SERI_S(ConfigFile)
{
    SERI_C(ConfigFile)

    fs::path configFolder = "../res/gen/config";
    std::string configName = "path.json";

    fs::path localizationFolder = "../res/gen/localization";
    std::string localizationName = "localization.json";

    fs::path logFolder = "../res/gen/logs";
    std::string logName = "logInternal.log";

    fs::path texturesFolder = "../res/images";
    SERI_COMPOSITE_V(ConfigTextures, textureNames);
};

#endif //SPACESHIPBP_CONFIGPATH_H
