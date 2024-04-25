#include "Level.h"
#include "Core/Application/ApplicationShortcuts.h"

Level::Level()
: entityDrawer(&renderTexture)
{
    renderTexture.create(getConfig().window.videoMode->width, getConfig().window.videoMode->height);
    renderTexture.setSmooth(true);
}

Level::Level(LevelTransitData&& transitData)
: entityDrawer(&renderTexture)
{
    systems = std::move(transitData.systems);
    entities = std::move(transitData.entities);
}

void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sf::Sprite(renderTexture.getTexture()), states);
}

void Level::Update(float dt)
{
    for (const auto& system: systems)
    {
        system->Update(dt);
    }

    renderTexture.clear(sf::Color::Transparent);
    entityDrawer.Update(dt);
    renderTexture.display();
}

LevelTransitData Level::ExtractTransitData()
{
    return {
        std::move(entitiesForTransit),
        std::move(systemsForTransit)
    };
}
