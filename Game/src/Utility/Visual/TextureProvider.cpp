#include "TexturesCache.h"
#include "Core/Application/ObjectsAggregator/GetterConfig.h"
#include "Core/Application/ObjectsAggregator/GetterLog.h"

TexturesCache::LoadErrorT TexturesCache::LoadResource(sf::Texture& texture, const fs::path& path)
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
