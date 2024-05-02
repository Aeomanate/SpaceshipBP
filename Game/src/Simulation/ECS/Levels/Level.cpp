#include "Level.h"
#include "Core/Application/ApplicationShortcuts.h"
#include "Simulation/ECS/Features/Visual/SEntityDrawer.h"
#include "Simulation/ECS/Features/Input/SInputInjector.h"

Level::Level()
{
}

Level::Level(Level&& otherLevel)
: dataStorageTransit { std::move(otherLevel.dataStorageTransit) }
, entityDrawer { std::move(otherLevel.entityDrawer) }
, inputInjector { std::move(otherLevel.inputInjector) }
{
    otherLevel.levelSystemsCache.clear();
    otherLevel.dataStorageLocal.systems.clear();
    otherLevel.dataStorageLocal.entities.clear();
}

void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(entityDrawer->GetDrawnState(), states);
}

void Level::Update(float dt)
{
    if(levelSystemsCache.empty())
    {
        CacheSystems();
    }

    for (auto& system: levelSystemsCache)
    {
        system->Update(dt);
    }
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

void Level::CacheSystems()
{
    std::vector<LevelDataStorage*> levelDataStorages {
        &dataStorageTransit,
        &dataStorageLocal
    };

    std::size_t totalSystems = 0;
    for(const auto& levelDataStorage: levelDataStorages)
    {
        totalSystems += levelDataStorage->systems.size();
    }

    levelSystemsCache.reserve(totalSystems);

    for(auto& levelDataStorage: levelDataStorages)
    {
        for(auto& system: levelDataStorage->systems)
        {
            levelSystemsCache.emplace_back(system.get());
        }
    }

    std::ranges::stable_sort(levelSystemsCache, [] (const ECS::System* a, const ECS::System* b) { return *a < *b; });
}
