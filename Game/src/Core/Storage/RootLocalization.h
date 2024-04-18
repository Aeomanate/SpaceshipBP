#ifndef SPACESHIPBP_ROOTLOCALIZATION_H
#define SPACESHIPBP_ROOTLOCALIZATION_H

#include "StorageRoot.h"
#include "Core/Storage/Localization/GeneralLocalization.h"

class RootLocalization: public StorageRoot
{
public:
    inline RootLocalization(): StorageRoot(&localization) { };

    SERI_ROOT_V(GeneralLocalization, localization);
};


#endif //SPACESHIPBP_ROOTLOCALIZATION_H
