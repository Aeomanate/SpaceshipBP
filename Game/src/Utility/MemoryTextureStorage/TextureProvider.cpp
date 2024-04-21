#include "TextureProvider.h"

FrameByFrame::FrameByFrame(const ConfigTexture& configTexture)
{
    fullSize = sprite.getTexture()->getSize();
    frameSize = configTexture.frameSize;
    sprite.setOrigin(sf::Vector2f(frameSize) / 2.0f);
}


void FrameByFrame::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

void FrameByFrame::advanceFrame() {

    sf::Vector2i pos = sf::Vector2i(
        cur_frame * sprite.getTexture()->getSize().x,
        cur_frame * sprite.getTexture()->getSize().y
    );


    sprite.setTextureRect( sf::IntRect( ) );
}



void TextureProvider::LoadTextures()
{
    getConfig().path.textureNames;
}

void TextureProvider::LoadTexture(const ConfigTexture& configTexture)
{
    sf::Texture texture;

    const fs::path& folder = getConfig().path.texturesFolder;
    std::string name = (folder / *configTexture.name).string();

    if(!texture.loadFromFile(name))
    {
        std::string details = name + " is oversize for load, max: " + std::to_string(sf::Texture::getMaximumSize()) + "px";
        Log(getLoc().fileOperations.textureOpenFailedWarning, details, Logger::Level::WARNING);
        return;
    }

    texture.setSmooth(true);
}
