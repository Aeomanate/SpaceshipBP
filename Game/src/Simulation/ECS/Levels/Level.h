#ifndef SPACESHIPBP_LEVEL_H
#define SPACESHIPBP_LEVEL_H

#include <vector>
#include <memory>
#include "SFML/Graphics/Drawable.hpp"
#include "Simulation/ECS/Entity.h"
#include "Simulation/ECS/System.h"
#include "Core/EventsHandling/ListenersEmitters.h"
#include "Core/Storage/Config/ConfigLevel.h"
#include "SFML/Graphics/RenderTexture.hpp"
#include "Simulation/ECS/BasicFeatures/Visual/SEntityDrawer.h"
#include "CLevelState.h"

struct LevelTransitData
{
    std::vector<std::unique_ptr<ECS::Entity>> entities;
    std::vector<std::unique_ptr<ECS::System>> systems;
};

class Level: public Updatable, public sf::Drawable
{
public:
    virtual ~Level() = default;

    Level();
    explicit Level(LevelTransitData&& transitData);

    template <class EorS>
    Level& AddUnique()
    {
        if constexpr (std::is_base_of_v<ECS::System, EorS>)
        { systemsUnique.emplace_back(std::make_unique<EorS>()); }
        else
        { entitiesUnique.emplace_back(std::make_unique<EorS>()); }

        return *this;
    }

    template <class EorS>
    Level& AddTransit()
    {
        if constexpr (std::is_base_of_v<ECS::System, EorS>)
        { systemsTransit.emplace_back(std::make_unique<EorS>()); }
        else
        { entitiesTransit.emplace_back(std::make_unique<EorS>()); }

        return *this;
    }

    LevelState GetCachedLevelState() const;
    void SetCachedLevelState(LevelState);


public:
    void Update(float dt) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public: // Emitters
    DATA_EMITTER(LevelCompleted, LevelTransitData);

private:
    LevelTransitData ExtractTransitData();

private:
    std::vector<std::unique_ptr<ECS::Entity>> entitiesUnique;
    std::vector<std::unique_ptr<ECS::System>> systemsUnique;

    std::vector<std::unique_ptr<ECS::Entity>> entitiesTransit;
    std::vector<std::unique_ptr<ECS::System>> systemsTransit;

    static inline sf::RenderTexture renderTexture;
    static inline SEntityDrawer entityDrawer { &renderTexture };

    LevelState cachedLevelState;
};


#endif //SPACESHIPBP_LEVEL_H
