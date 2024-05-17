#ifndef SPACESHIPBP_TEXTURESCACHE_H
#define SPACESHIPBP_TEXTURESCACHE_H

#include "Utility/ResourcesCache.h"
#include "Core/Storage/Config/ConfigTextures.h"

class TexturesCache: public ResourcesCache<TexturesCache, sf::Texture, &ConfigTextures::player>
{
    CUSTOM_RESOURCE_LOADER(sf::Texture);
};


#endif //SPACESHIPBP_TEXTURESCACHE_H
