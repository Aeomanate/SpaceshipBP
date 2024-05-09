#include "FrameByFrame.h"
#include "Core/Application/ApplicationShortcuts.h"
#include "Utility/Math/Vectors.h"

FrameByFrame::FrameByFrame(const ConfigTexture& configTexture)
: framesTotal { configTexture.framesTotal }
, frameIntervalMs { configTexture.frameIntervalMs / 1000.f }
, fullSize { getTextureProvider().GetTexture(configTexture).getSize() }
, frameSizePx { configTexture.frameSizePx }
, framesCountBy { sf::Vector2u {
    fullSize.x / configTexture.frameSizePx->x,
    fullSize.y / configTexture.frameSizePx->y}}
, repeatsCount { configTexture.repeatsCount }
{
    const sf::Texture& texture = getTextureProvider().GetTexture(configTexture);

    sprite.setTexture(texture);
    sprite.setOrigin(frameSizePx * toVector2f(configTexture.origin));
    sprite.setTextureRect(CalcSpriteRect());
}

FrameByFrame& FrameByFrame::operator =(const ConfigTexture& configTexture)
{
    *this = std::move(FrameByFrame(configTexture));
    return *this;
}

void FrameByFrame::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

void FrameByFrame::AdvanceFrame(float dt) {
    if(framesTotal == 1 || repeatsCurrent == repeatsCount )
    {
        return;
    }

    timeSinceLastAdvance += dt;
    if(timeSinceLastAdvance < frameIntervalMs)
    { return; }
    timeSinceLastAdvance -= frameIntervalMs;

    sf::Uint32 nextFrame = curFrame + 1;
    repeatsCurrent += nextFrame == framesTotal;
    curFrame = nextFrame % framesTotal;

    sprite.setTextureRect(CalcSpriteRect());
}

sf::IntRect FrameByFrame::CalcSpriteRect() const
{
    sf::IntRect rect;

    rect.width = frameSizePx.x;
    rect.height = frameSizePx.y;

    rect.left = frameSizePx.x * (curFrame % framesCountBy.x);
    rect.top = frameSizePx.y * (curFrame % framesCountBy.y);

    return rect;
}
