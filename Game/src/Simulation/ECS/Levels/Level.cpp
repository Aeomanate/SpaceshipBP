#include "Level.h"
#include "Core/Application/ApplicationShortcuts.h"

Level::Level()
{
    renderTexture.create(getConfig().window.videoMode->width, getConfig().window.videoMode->height);
    renderTexture.setSmooth(true);
}

Level::Level(LevelTransitData&& transitData)
{
    systemsUnique = std::move(transitData.systems);
    entitiesUnique = std::move(transitData.entities);
}

void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sf::Sprite(renderTexture.getTexture()), states);
}

void Level::Update(float dt)
{
    renderTexture.clear(sf::Color::Transparent);
    for (const auto& system: systemsUnique)
    {
        system->Update(dt);
    }
    renderTexture.display();
}

LevelTransitData Level::ExtractTransitData()
{
    return {
        std::move(entitiesTransit),
        std::move(systemsTransit)
    };
}

LevelState Level::GetCachedLevelState() const
{
    return cachedLevelState;
}

void Level::SetCachedLevelState(LevelState levelState)
{
    cachedLevelState = levelState;
}
