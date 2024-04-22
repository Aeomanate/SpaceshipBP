#ifndef FUSEGAME_MEMORYTEXTURESTORAGE_HPP
#define FUSEGAME_MEMORYTEXTURESTORAGE_HPP

#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "Utility/SystemRelated/SystemRelated.h"


class FrameByFrame: public sf::Drawable {
public:
    FrameByFrame(const ConfigTexture& configTexture);

    void Load();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    void advanceFrame();

private:
    sf::Sprite sprite;
    sf::Vector2u fullSize;
    sf::Vector2u frameSize;
    sf::Vector2u frameCount;

    int repeatsCount = 0;
    int repeatsCurrent = 0;
    std::size_t cur_frame = 0;

    sf::Time frameInterval;
    sf::Clock clock;
};


class TextureProvider
{
public:
    void LoadTextures();

    FrameByFrame CreateFrameByFrame(const ConfigTexture& configTexture);

private:
    void LoadTexture(const ConfigTexture& configTexture);

private:
    std::unordered_map<std::string, sf::Texture> textures;
};

#endif // FUSEGAME_MEMORYTEXTURESTORAGE_HPP
