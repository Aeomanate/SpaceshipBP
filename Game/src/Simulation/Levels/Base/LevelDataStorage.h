#ifndef SPACESHIPBP_LEVELDATASTORAGE_H
#define SPACESHIPBP_LEVELDATASTORAGE_H

#include <vector>
#include <memory>
#include "Simulation/ECS/Entity.h"
#include "Simulation/ECS/System.h"

struct LevelDataStorage
{
    enum class MigrationPolicy
    {
        LOCAL,
        TRANSIT
    };

    template <class EorS, class... Params>
    void Add(Params&&... initPack)
    {
        if constexpr (std::is_base_of_v<ECS::System, EorS>)
        { systems.emplace_back(std::make_unique<EorS>(std::forward<Params>(initPack)...)); }
        else
        { entities.emplace_back(std::make_unique<EorS>(std::forward<Params>(initPack)...)); }
    }

    std::vector<std::unique_ptr<ECS::Entity>> entities;
    std::vector<std::unique_ptr<ECS::System>> systems;
};

struct LevelDataStorageTransit: public LevelDataStorage
{ };

struct LevelDataStorageLocal: public LevelDataStorage
{ };

#endif //SPACESHIPBP_LEVELDATASTORAGE_H
