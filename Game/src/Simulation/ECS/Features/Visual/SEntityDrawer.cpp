#include "SEntityDrawer.h"
#include "Core/Application/ObjectsAggregator/GetterConfig.h"
#include "Simulation/ECS/Features/Visual/CSceneElement.h"
#include "Simulation/ECS/Features/Movable/CPosition.h"
#include "Simulation/ECS/Entity.h"
#include <ranges>
#include <algorithm>

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
    sf::RenderStates states;
    renderTexture.clear(sf::Color::Transparent);

    for(auto& [entity, sceneElement]: CSceneElement::AllSorted())
    {
        if(auto* position = entity->TryGetDataAs<CPosition>(); position)
        {
            states.transform.translate(position->value);
            renderTexture.draw(sceneElement->sprite, states);
            continue;
        }
        renderTexture.draw(sceneElement->sprite);
    }

    renderTexture.display();
}
