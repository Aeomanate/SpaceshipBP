#include "SEntityMover.h"

#include "CPhysics.h"
#include "CPosition.h"

void SEntityMover::Update(float dt)
{
    for(auto& [entity, pos]: CPosition::AllEntities() | CPhysics::Filter())
    {
        sf::Vector2f& f = CPhysics::Data(entity).appliedForces;
        sf::Vector2f& v = CPhysics::Data(entity).speed;
        float& m = CPhysics::Data(entity).mass;

        sf::Vector2f a = f / m;
        v += a * dt * 0.5f;
        pos.value += v * dt;
        v += a * dt * 0.5f;
    }
}
