#include "SEntityMover.h"

#include "CSpeed.h"
#include "CPosition.h"
#include "CAppliedForces.h"
#include "CMass.h"
#include "Simulation/ECS/Component.h"
#include "CAppliedForces.h"

void SEntityMover::Update(float dt)
{
    for(auto& [entity, pos]: CPosition::AllEntities() | CSpeed::Filter() | CAppliedForces::Filter() | CMass::Filter())
    {
        sf::Vector2f& f = CAppliedForces::Data(entity).value;
        sf::Vector2f& v = CSpeed::Data(entity).value;
        float& m = CMass::Data(entity).m;

        sf::Vector2f a = f / m;
        v += a * dt * 0.5f;
        pos.value += v * dt;
        v += a * dt * 0.5f;
    }
}
