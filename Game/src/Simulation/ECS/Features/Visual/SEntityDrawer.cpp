#include "SEntityDrawer.h"
#include "Core/Application/ApplicationShortcuts.h"
#include "Simulation/ECS/Features/Visual/CAnimation.h"
#include "Simulation/ECS/Features/Movable/CPosition.h"

SEntityDrawer::SEntityDrawer()
: ECS::System(ECS::System::Order::POST_GAMEPLAY)
{
    renderTexture.create(getConfig().window.videoMode->width, getConfig().window.videoMode->height);
    renderTexture.setSmooth(true);
}

sf::Sprite SEntityDrawer::GetDrawnState()
{
    return sf::Sprite(renderTexture.getTexture());
}

void SEntityDrawer::Update(float)
{
    renderTexture.clear(sf::Color::Transparent);

    sf::RenderStates states;

    for(auto& [entity, sprite]: CAnimation::AllEntities())
    {
        if(auto position = entity->TryGetDataAs<CPosition>(); position)
        {
            states.transform.translate(*position);
            renderTexture.draw(sprite, states);
        }
        renderTexture.draw(sprite);
    }

    renderTexture.display();
}
