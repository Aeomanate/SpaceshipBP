#ifndef SPACESHIPBP_APPLICATIONLOCALIZATION_H
#define SPACESHIPBP_APPLICATIONLOCALIZATION_H

#include <rapidjson/document.h>
#include "Utility/Serialization/Serializable.h"
#include "LocalizationLogLevel.h"
#include "LocalizationFileOperations.h"
#include "Core/UserJsonConversions.h"
#include <string>

struct ApplicationLocalization: public Serialization::SerializableStruct<UserJsonConversions>
{
    LocalizationLogLevel logLevel;
    LocalizationFileOperations fileOperations;
    std::string parseJsonWarning = "Parse failed, incorrect JSON";

};




#endif //SPACESHIPBP_APPLICATIONLOCALIZATION_H
