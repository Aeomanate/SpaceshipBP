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
        CAppliedForces& f = CAppliedForces::Data(entity);
        CSpeed& v = CSpeed::Data(entity);
        float& m = CMass::Data(entity).m;

        sf::Vector2f a = f / m;
        v += a * dt * 0.5f;
        pos += v * dt;
        v += a * dt * 0.5f;
    }
}
