#ifndef SPACESHIPBP_GENERALLOCALIZATION_H
#define SPACESHIPBP_GENERALLOCALIZATION_H

#include <rapidjson/document.h>
#include "Utility/Serialization/Serializable.h"
#include "LocLogLevel.h"
#include "LocFileOperations.h"
#include "Core/Storage/UserJsonConversions.h"
#include <string>

SERIALIZABLE_STRUCT(GeneralLocalization)
{
    LocLogLevel logLevel;
    LocFileOperations fileOperations;
    std::string parseJsonWarning = "Parse failed, incorrect JSON";

};




#endif //SPACESHIPBP_GENERALLOCALIZATION_H
