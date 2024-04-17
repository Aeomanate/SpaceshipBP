#ifndef SPACESHIPBP_LOCALIZATIONFILEOPERATIONS_H
#define SPACESHIPBP_LOCALIZATIONFILEOPERATIONS_H

#include "Utility/Serialization/Serializable.h"

struct LocalizationFileOperations
{
    std::string absentNotify = "Absent file";
    std::string createNotify = "Creating absent file";
    std::string createFailed = "Failed creating file";
};


#endif //SPACESHIPBP_LOCALIZATIONFILEOPERATIONS_H
