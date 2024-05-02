#ifndef FUSEGAME_MEMORYTEXTURESTORAGE_HPP
#define FUSEGAME_MEMORYTEXTURESTORAGE_HPP

#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "Core/Storage/Config/ConfigTexture.h"

class FrameByFrame: public sf::Drawable {
public:
    FrameByFrame(const ConfigTexture& configTexture);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void AdvanceFrame(float dt);

private:
    sf::IntRect CalcSpriteRect();

private:
    sf::Sprite sprite;
    const sf::Uint32 framesTotal;
    const float frameIntervalMs;
    const sf::Vector2u fullSize;
    const sf::Vector2u frameSizePx;
    const sf::Vector2u framesCountBy;

    std::size_t curFrame = 0;

    const sf::Int32 repeatsCount = 0;
    sf::Int32 repeatsCurrent = 0;

    float timeSinceLastAdvance = 0;
};

#endif // FUSEGAME_MEMORYTEXTURESTORAGE_HPP
