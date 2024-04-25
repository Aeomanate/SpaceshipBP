#ifndef SPACESHIPBP_TEXTUREPROVIDER_H
#define SPACESHIPBP_TEXTUREPROVIDER_H

#include "Core/Storage/Config/ConfigTexture.h"

class TextureProvider
{
public:
    void LoadTextures();
    const sf::Texture& GetTexture(const ConfigTexture& configTexture) const;

private:
    void LoadTexture(const ConfigTexture& configTexture);

private:
    std::unordered_map<std::string_view, sf::Texture> textures;
};


#endif //SPACESHIPBP_TEXTUREPROVIDER_H
