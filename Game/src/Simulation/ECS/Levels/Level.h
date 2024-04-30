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
#include "Simulation/ECS/BasicFeatures/Visual/SEntityDrawer.h"
#include "CLevelState.h"
#include "Simulation/ECS/BasicFeatures/Input/SInputInjector.h"

struct LevelDataStorage
{
    friend struct LevelData;

    enum class MigrationPolicy
    {
        LOCAL,
        TRANSIT
    };

    template <class EorS>
    void Add()
    {
        if constexpr (std::is_base_of_v<ECS::System, EorS>)
        { systems.emplace_back(std::make_unique<EorS>()); }
        else
        { entities.emplace_back(std::make_unique<EorS>()); }
    }

    std::vector<std::unique_ptr<ECS::Entity>> entities;
    std::vector<std::unique_ptr<ECS::System>> systems;
};

struct LevelDataStorageTransit: public LevelDataStorage
{ };

struct LevelDataStorageLocal: public LevelDataStorage
{ };

struct LevelData
{
    void InjectDataStorages(std::vector<LevelDataStorage*> levelDataStorages);

    std::vector<ECS::Entity*> entities;
    std::vector<ECS::System*> systems;
};

class Level: public Updatable, public sf::Drawable
{
public:
    void Update(float dt) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    virtual ~Level() = default;

    Level();
    explicit Level(LevelDataStorageTransit&& transitData);

    LevelState GetCachedLevelState() const;
    void SetCachedLevelState(LevelState);

    template <class EorS, LevelDataStorage::MigrationPolicy MIGRATION_POLICY>
    void Add()
    {
        if constexpr (MIGRATION_POLICY == LevelDataStorage::MigrationPolicy::LOCAL)
        {
            dataStorageLocal.Add<EorS>();
        }
        else if constexpr (MIGRATION_POLICY == LevelDataStorage::MigrationPolicy::TRANSIT){
            dataStorageTransit.Add<EorS>();
        }
    }

    SInputInjector& GetInputInjector();

public: // Emitters
    DATA_EMITTER(LevelCompleted, LevelDataStorageTransit);

protected:
    void InjectStorages();

protected:
    LevelData levelData;

private:
    LevelState cachedLevelState;

    LevelDataStorageTransit dataStorageTransit;
    LevelDataStorageLocal dataStorageLocal;

    sf::RenderTexture renderTexture;
    SEntityDrawer* entityDrawer;

    SInputInjector* inputInjector;
};


#endif //SPACESHIPBP_LEVEL_H
