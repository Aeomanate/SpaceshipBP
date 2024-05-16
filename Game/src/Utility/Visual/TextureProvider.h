#ifndef SPACESHIPBP_TEXTUREPROVIDER_H
#define SPACESHIPBP_TEXTUREPROVIDER_H

#include "Utility/ResourcesProvider.h"
#include "Core/Storage/Config/ConfigTextures.h"

class TextureProvider: public ResourcesProvider<TextureProvider, sf::Texture, &ConfigTextures::player>
{
    CUSTOM_RESOURCE_LOADER(sf::Texture);
};


#endif //SPACESHIPBP_TEXTUREPROVIDER_H
