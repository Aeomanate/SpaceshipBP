#include "FontProvider.h"

FontsCache::LoadErrorT FontsCache::LoadResource(sf::Font& out, const fs::path& path)
{
    if(!out.loadFromFile(path.generic_string()))
    {
        return path.string()
            + " is missing or oversize for load, max: "
            + std::to_string(sf::Texture::getMaximumSize()) + "px";
    }

    return std::nullopt;
}
