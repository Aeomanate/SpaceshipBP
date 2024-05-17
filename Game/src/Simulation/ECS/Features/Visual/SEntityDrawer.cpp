#include "SEntityDrawer.h"
#include <ranges>
#include <algorithm>
#include "Core/Application/ObjectsAggregator/GetterConfig.h"
#include "Simulation/ECS/ECS.h"

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

    for(auto& [entity, sceneElement]: CSceneElement::AllSorted())
    {
        if(auto* position = entity->TryGetDataAs<CPosition>(); position)
        {
            renderTexture.draw(sceneElement->sprite, sf::Transform().translate(position->value));
            continue;
        }
        renderTexture.draw(sceneElement->sprite);
    }

    for(auto& [entity, text]: CText::All())
    {
        if(auto* position = entity->TryGetDataAs<CPosition>(); position)
        {
            renderTexture.draw(*text, sf::Transform().translate(position->value));
            continue;
        }
        renderTexture.draw(*text);
    }

    renderTexture.display();
}
