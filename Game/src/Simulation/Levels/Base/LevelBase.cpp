#include "LevelBase.h"
#include "Core/Application/ApplicationShortcuts.h"
#include "Simulation/ECS/Features/Visual/SEntityDrawer.h"
#include "Simulation/ECS/Features/Input/SInputInjector.h"

void LevelBase::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(entityDrawer->GetDrawnState(), states);
}

void LevelBase::Update(float dt)
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

LevelState LevelBase::GetCachedLevelState() const
{
    return cachedLevelState;
}

void LevelBase::SetCachedLevelState(LevelState levelState)
{
    cachedLevelState = levelState;
}

SInputInjector& LevelBase::GetInputInjector()
{
    return *inputInjector;
}

void LevelBase::CacheSystems()
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
