#include "SSpriteAnimator.h"
#include "CAnimation.h"

void SSpriteAnimator::Update(float dt)
{
    for (auto& [entity, animation]: CAnimation::AllEntities())
    {
        animation->AdvanceFrame(dt);
    }
}
