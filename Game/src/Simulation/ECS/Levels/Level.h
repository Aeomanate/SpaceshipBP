#ifndef SPACESHIPBP_LEVEL_H
#define SPACESHIPBP_LEVEL_H

#include <vector>
#include <set>
#include <memory>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include "Simulation/ECS/Entity.h"
#include "Simulation/ECS/System.h"
#include "Core/EventsHandling/ListenersEmitters.h"
#include "Core/Storage/Config/ConfigLevel.h"
#include "CLevelState.h"

class SEntityDrawer;
class SInputInjector;

struct LevelDataStorage
{
    friend struct LevelSystems;

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

class Level: public Updatable, public sf::Drawable
{
public:
    void Update(float dt) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    virtual ~Level() = default;

    Level();
    explicit Level(Level&& otherLevel);

    LevelState GetCachedLevelState() const;
    void SetCachedLevelState(LevelState);

    template <class EorS, LevelDataStorage::MigrationPolicy MIGRATION_POLICY, class... Params>
    void Add(Params&&... initPack)
    {
        auto choiceLevelDataStorage = [this] () -> LevelDataStorage& {
            if constexpr (MIGRATION_POLICY == LevelDataStorage::MigrationPolicy::LOCAL)
            { return this->dataStorageLocal;   }
            else if constexpr (MIGRATION_POLICY == LevelDataStorage::MigrationPolicy::TRANSIT)
            { return this->dataStorageTransit; }
        };

        choiceLevelDataStorage().template Add<EorS>(std::forward<Params>(initPack)...);

        auto catchSystem = [&choiceLevelDataStorage] <class System> (System*& systemPtr) {
            if constexpr (std::is_base_of_v<System, EorS> || std::is_convertible_v<System, EorS>)
            { systemPtr = static_cast<System*>(choiceLevelDataStorage().systems.back().get()); }
        };

        catchSystem(entityDrawer);
        catchSystem(inputInjector);
    }


    SInputInjector& GetInputInjector();

public: // Emitters
    DATA_EMITTER(LevelCompleted, LevelDataStorageTransit);

private:
    // Called when firstly entered into an update loop.
    void CacheSystems();

private:
    LevelState cachedLevelState;

    LevelDataStorageTransit dataStorageTransit;
    LevelDataStorageLocal dataStorageLocal;
    std::vector<ECS::System*> levelSystemsCache;

    SEntityDrawer* entityDrawer = nullptr;
    SInputInjector* inputInjector = nullptr;
};


#endif //SPACESHIPBP_LEVEL_H
