#include "TextureProvider.h"
#include "Core/Application/Getters/ConfigGetter.h"
#include "Core/Application/Getters/LogGetter.h"

TextureProvider::LoadErrorT TextureProvider::LoadResource(sf::Texture& texture, const fs::path& path)
{
    if(!texture.loadFromFile(path.generic_string()))
    {
        return path.string()
            + " is missing or oversize for load, max: "
            + std::to_string(sf::Texture::getMaximumSize()) + "px";
    }

    texture.setSmooth(true);
    return std::nullopt;
}
