#ifndef SPACESHIPBP_CONFIGLOCALIZATION_H
#define SPACESHIPBP_CONFIGLOCALIZATION_H

#include <rapidjson/document.h>
#include "Utility/Serialization/Serializable.h"
#include "ConfigLocalizationLogLevel.h"
#include "ConfigLocalizationFileOperations.h"
#include <string>

struct ConfigLocalization
{
    ConfigLocalizationLogLevel logLevel;
    ConfigLocalizationFileOperations fileOperations;
    std::string parseJsonWarning = "Parse failed, incorrect JSON";

};




#endif //SPACESHIPBP_CONFIGLOCALIZATION_H
