#ifndef SPACESHIPBP_CONFIGLOCALIZATIONFILEOPERATIONS_H
#define SPACESHIPBP_CONFIGLOCALIZATIONFILEOPERATIONS_H

#include "Utility/Serialization/Serializable.h"

struct ConfigLocalizationFileOperations: public SerializableStruct
{
    std::string absentNotify = "Absent file";
    std::string createNotify = "Creating absent file";
    std::string createFailed = "Failed creating file";
};


#endif //SPACESHIPBP_CONFIGLOCALIZATIONFILEOPERATIONS_H
