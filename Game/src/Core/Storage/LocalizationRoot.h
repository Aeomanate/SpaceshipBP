#ifndef SPACESHIPBP_LOCALIZATIONROOT_H
#define SPACESHIPBP_LOCALIZATIONROOT_H

#include "StorageRoot.h"
#include "Core/Storage/Localization/ApplicationLocalization.h"

class LocalizationRoot: public StorageRoot
{
public:
    inline LocalizationRoot(): StorageRoot(&localization) { };

    ApplicationLocalization localization;
};


#endif //SPACESHIPBP_LOCALIZATIONROOT_H
