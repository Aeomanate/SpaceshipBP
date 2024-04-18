#ifndef SPACESHIPBP_CONFIGFILE_H
#define SPACESHIPBP_CONFIGFILE_H

#include <filesystem>
namespace fs = std::filesystem;

#include "Utility/Serialization/Serializable.h"
#include "Core/Storage/GameJsonConversions.h"


SERI_S(ConfigFile)
{
    SERI_C(ConfigFile)

    fs::path folder = "../Artifacts/Config";
    SERI_STR_V(Name, "config.json");
};

#endif //SPACESHIPBP_CONFIGFILE_H
