#ifndef SPACESHIPBP_CONFIGLOCALIZATIONLOGLEVEL_H
#define SPACESHIPBP_CONFIGLOCALIZATIONLOGLEVEL_H

#include "Utility/Serialization/Serializable.h"

struct ConfigLocalizationLogLevel: public SerializableStruct
{
    std::string verbose = "Verbose";
    std::string notify = "Notify";
    std::string warning = "Warning";
    std::string error = "Error";
    std::string fatalError = "Fatal Error";
};


#endif //SPACESHIPBP_CONFIGLOCALIZATIONLOGLEVEL_H
