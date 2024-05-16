#ifndef FUSEGAME_MEMORYTEXTURESTORAGE_HPP
#define FUSEGAME_MEMORYTEXTURESTORAGE_HPP

#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "Core/Storage/Config/ConfigTexture.h"

class FrameByFrame: public sf::Drawable {
public:
    FrameByFrame() = default;
    FrameByFrame(const ConfigTexture& configTexture);
    FrameByFrame& operator= (const ConfigTexture& configTexture);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void AdvanceFrame(float dt);

private:
    sf::IntRect CalcSpriteRect() const;

private:
    sf::Sprite sprite;
    sf::Int32 framesTotal = 0;
    float frameIntervalMs = 0;
    sf::Vector2i fullSize = {0, 0};
    sf::Vector2i frameSizePx = {0, 0};
    sf::Vector2i framesCountBy = {0, 0};

    sf::Int32 curFrame = 0;

    sf::Int32 repeatsCount = 0;
    sf::Int32 repeatsCurrent = 0;

    float timeSinceLastAdvance = 0;
};

#endif // FUSEGAME_MEMORYTEXTURESTORAGE_HPP
