#ifndef SPACESHIPBP_LEVELBASE_H
#define SPACESHIPBP_LEVELBASE_H

#include <ranges>
#include <iterator>
#include "SFML/Graphics/Drawable.hpp"
#include "Core/EventsHandling/ListenersEmitters.h"
#include "Utility/Updatable.h"
#include "LevelDataStorage.h"
#include "Simulation/ECS/Features/Levels/CLevelState.h"

class SEntityDrawer;
class SInputInjector;

class LevelBase: public Updatable, public sf::Drawable
{
public:
    using LevelPtr = std::unique_ptr<LevelBase>;

    template <LevelDataStorage::MigrationPolicy POLICY>
    struct AddHelper {
        LevelBase* levelPtr = nullptr;

        template <class EorS, class... Params>
        AddHelper& Add(Params&&... args)
        {
            levelPtr->template Add<EorS, POLICY, Params...>(std::forward<Params>(args)...);
            return *this;
        }
    };


public:
    void Update(float dt) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    void Transit(std::unique_ptr<LevelBase> prevLevel)
    {
        dataStorageTransit = std::move(prevLevel->dataStorageTransit);
        entityDrawer = prevLevel->entityDrawer;
        inputInjector = prevLevel->inputInjector;
        prevLevel->entityDrawer = nullptr;
        prevLevel->inputInjector = nullptr;
    }


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

    template <LevelDataStorage::MigrationPolicy POLICY>
    AddHelper<POLICY> AddAs()
    { return AddHelper<POLICY> { this }; }


    SInputInjector& GetInputInjector();

public: // Emitters
    DATA_EMITTER(LevelCompleted, LevelDataStorageTransit);

protected:
    LevelBase() = default;

private:
    // Called when firstly entered into an update loop.
    // It's collect raw pointers to all systems into one loop-friendly array
    void CacheSystems();

private:
    LevelState cachedLevelState = LevelState::STARTING;

    LevelDataStorageTransit dataStorageTransit;
    LevelDataStorageLocal dataStorageLocal;
    std::vector<ECS::System*> levelSystemsCache;

    SEntityDrawer* entityDrawer = nullptr;
    SInputInjector* inputInjector = nullptr;
};

#endif //SPACESHIPBP_LEVELBASE_H
