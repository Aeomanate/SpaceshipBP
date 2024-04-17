#ifndef SPACESHIPBP_LOCALIZATIONLOGLEVEL_H
#define SPACESHIPBP_LOCALIZATIONLOGLEVEL_H

#include "Utility/Serialization/Serializable.h"

struct LocalizationLogLevel
{
    std::string verbose = "Verbose";
    std::string notify = "Notify";
    std::string warning = "Warning";
    std::string error = "Error";
    std::string fatalError = "Fatal Error";
};


#endif //SPACESHIPBP_LOCALIZATIONLOGLEVEL_H
