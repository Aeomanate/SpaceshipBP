#ifndef SPACESHIPBP_TEXTUREPROVIDER_H
#define SPACESHIPBP_TEXTUREPROVIDER_H

#include "Utility/ResourcesProvider.h"
#include "Core/Storage/Config/ConfigTextures.h"

class TextureProvider: public ResourcesProvider<TextureProvider, sf::Texture, &ConfigTextures::player>
{
public:
    static LoadErrorT LoadResource(sf::Texture& out, const fs::path& path);
};


#endif //SPACESHIPBP_TEXTUREPROVIDER_H
