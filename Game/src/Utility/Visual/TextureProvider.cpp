#include "TextureProvider.h"
#include "Core/Application/ApplicationShortcuts.h"


void TextureProvider::LoadTextures()
{
    getConfig().textures.Visit([thisPtr=this](const ConfigTexture& configTexture){
        thisPtr->LoadTexture(configTexture);
    });
}

void TextureProvider::LoadTexture(const ConfigTexture& configTexture)
{
    Log(getLoc().fileOperations.textureOpeningNotify, configTexture.name);
    auto [it, isInserted] = textures.try_emplace(*configTexture.name, sf::Texture{});
    if(!isInserted)
    {
        Log(getLoc().logLevel.error, "Unable to insert empty texture to the map", Logger::Level::ERROR);
        return;
    }

    sf::Texture& texture = it->second;

    const fs::path& folder = getConfig().path.texturesFolder;
    std::string name = (folder / *configTexture.name).string();

    if(!texture.loadFromFile(name))
    {
        std::string details = name
            + " is missing or oversize for load, max: "
            + std::to_string(sf::Texture::getMaximumSize()) + "px";
        Log(getLoc().fileOperations.textureOpenFailedWarning, details, Logger::Level::WARNING);
        return;
    }

    texture.setSmooth(true);
}

const sf::Texture& TextureProvider::GetTexture(const ConfigTexture& configTexture) const
{
    static const ConfigTexture* lastRequestedConfig = &configTexture;
    static const sf::Texture* lastRequestedTexture = &textures.at(*configTexture.name);

    if(lastRequestedConfig != &configTexture)
    {
        lastRequestedConfig = &configTexture;
        lastRequestedTexture = &textures.at(*configTexture.name);
    }

    return *lastRequestedTexture;
}
