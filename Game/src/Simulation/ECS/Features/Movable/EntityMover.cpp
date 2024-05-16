#include "SEntityMover.h"

#include "Simulation/ECS/Entity.h"
#include "CPhysics.h"
#include "CPosition.h"
#include "Utility/Math/Vectors.h"
#include "Core/Application/Getters/LogGetter.h"

void SEntityMover::Update(float dt)
{
    for(auto& [entity, pos]: CPosition::All() | CPhysics::Filter())
    {
        CPhysics& physics = REF(entity->TryGetDataAs<CPhysics>());
        sf::Vector2f& f = physics.appliedForces;
        sf::Vector2f& v = physics.speed;
        float& m = physics.mass;

        bool isForcesSemiZero = isSemiZero(physics.appliedForces);
        bool isSpeedSemiZero = isSemiZero(physics.speed);

        if(isForcesSemiZero && isSpeedSemiZero)
        { continue; }

        sf::Vector2f a = f / m;
        v += a * dt * 0.5f;
        *pos += v * dt;
        v += a * dt * 0.5f;

        Log(getLoc().simulation.playerMovingVerbose,
            std::format("EntityMover. F: {:>5}={}, V: {:>5}={}, P: {}",
                        !isForcesSemiZero, toString(f), !isSpeedSemiZero, toString(v), toString(*pos)),
            Logger::Level::VERBOSE);

        physics.appliedForces = sf::Vector2f{0, 0};
    }
}
