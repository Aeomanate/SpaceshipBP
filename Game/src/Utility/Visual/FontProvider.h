#ifndef SPACESHIPBP_FONTPROVIDER_H
#define SPACESHIPBP_FONTPROVIDER_H

#include "SFML/Graphics/Font.hpp"
#include "Core/Storage/Config/ConfigFonts.h"
#include "Utility/ResourcesProvider.h"

class FontProvider: public ResourcesProvider<FontProvider, sf::Font, &ConfigFonts::basicFont>
{
    CUSTOM_RESOURCE_LOADER(sf::Font);
};


#endif //SPACESHIPBP_FONTPROVIDER_H
