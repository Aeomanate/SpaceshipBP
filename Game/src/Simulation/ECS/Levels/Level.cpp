#include "Level.h"
#include "Core/Application/ApplicationShortcuts.h"

void LevelData::InjectDataStorages(std::vector<LevelDataStorage*> levelDataStorages)
{
    std::size_t totalEntities = 0;
    std::size_t totalSystems = 0;
    for(const auto& levelDataStorage: levelDataStorages)
    {
        totalEntities += levelDataStorage->entities.size();
        totalSystems += levelDataStorage->systems.size();
    }

    entities.reserve(totalEntities);
    systems.reserve(totalSystems);

    for(auto& levelDataStorage: levelDataStorages)
    {
        for(auto& entity: levelDataStorage->entities)
        {
            entities.emplace_back(entity.get());
        }

        for(auto& system: levelDataStorage->systems)
        {
            systems.emplace_back(system.get());
        }
    }

    std::ranges::sort(systems, [] (const ECS::System* a, const ECS::System* b) { return *a < *b; });
}



Level::Level()
{
    renderTexture.create(getConfig().window.videoMode->width, getConfig().window.videoMode->height);
    renderTexture.setSmooth(true);
}

Level::Level(LevelDataStorageTransit&& transitData)
: dataStorageTransit { std::move(transitData) }
{ }

void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sf::Sprite(renderTexture.getTexture()), states);
}

void Level::Update(float dt)
{
    renderTexture.clear(sf::Color::Transparent);
    for (auto& system: levelData.systems)
    {
        system->Update(dt);
    }
    renderTexture.display();
}

LevelState Level::GetCachedLevelState() const
{
    return cachedLevelState;
}

void Level::SetCachedLevelState(LevelState levelState)
{
    cachedLevelState = levelState;
}

SInputInjector& Level::GetInputInjector()
{
    return *inputInjector;
}

void Level::InjectStorages()
{
    levelData.InjectDataStorages({
        &dataStorageLocal,
        &dataStorageTransit
    });
}
