#include "SSpriteAnimator.h"
#include "CSceneElement.h"

void SSpriteAnimator::Update(float dt)
{
    for (auto& [entity, animation]: CSceneElement::All())
    {
        animation.sprite.AdvanceFrame(dt);
    }
}
