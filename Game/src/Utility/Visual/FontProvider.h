#ifndef SPACESHIPBP_FONTPROVIDER_H
#define SPACESHIPBP_FONTPROVIDER_H

#include "SFML/Graphics/Font.hpp"
#include "Core/Storage/Config/ConfigFonts.h"
#include "Utility/ResourcesCache.h"

class FontsCache: public ResourcesCache<FontsCache, sf::Font, &ConfigFonts::basicFont>
{
    CUSTOM_RESOURCE_LOADER(sf::Font);
};


#endif //SPACESHIPBP_FONTPROVIDER_H
