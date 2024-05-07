#include "SEntityMover.h"

#include "Simulation/ECS/Entity.h"
#include "CPhysics.h"
#include "CPosition.h"
#include "Utility/Math/Vectors/Vectors.h"

void SEntityMover::Update(float dt)
{
    for(auto& [entity, pos]: CPosition::All() | CPhysics::Filter())
    {
        CPhysics& physics = *entity->TryGetDataAs<CPhysics>().value();

        if(isSemiZero(physics.appliedForces) && isSemiZero(physics.speed))
        { continue; }

        sf::Vector2f& f = physics.appliedForces;
        sf::Vector2f& v = physics.speed;
        float& m = physics.mass;

        sf::Vector2f a = f / m;
        v += a * dt * 0.5f;
        *pos += v * dt;
        v += a * dt * 0.5f;

        physics.appliedForces = { };
    }
}
