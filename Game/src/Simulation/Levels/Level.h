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

    template <class Thing, class... ThingParams>
    Level& AddThing(ThingParams&&... thingInitPack)
    {
        if constexpr (std::is_base_of_v<ECS::System, Thing>())
        { systems.emplace_back(std::make_unique<Thing>(std::forward(thingInitPack)...)); }
        else
        {  entities.emplace_back(std::make_unique<Thing>(std::forward(thingInitPack...))); }

        return *this;
    }

    template <class Thing, class... ThingParams>
    Level& AddThingForTransit(ThingParams&&... thingInitPack)
    {
        if constexpr (std::is_base_of_v<ECS::System, Thing>())
        { systemsForTransit.emplace_back(std::make_unique<Thing>(std::forward(thingInitPack)...)); }
        else
        {  entitiesForTransit.emplace_back(std::make_unique<Thing>(std::forward(thingInitPack...))); }

        return *this;
    }

    LevelTransitData ExtractTransitData();

public:
    void Update(float dt) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public: // Emitters
    DATA_EMITTER(EndLevel, LevelTransitData);

private:

private:

    std::vector<std::unique_ptr<ECS::Entity>> entities;
    std::vector<std::unique_ptr<ECS::Entity>> entitiesForTransit;
    std::vector<std::unique_ptr<ECS::System>> systems;
    std::vector<std::unique_ptr<ECS::System>> systemsForTransit;

    sf::RenderTexture renderTexture;
    SEntityDrawer entityDrawer;
};


#endif //SPACESHIPBP_LEVEL_H
