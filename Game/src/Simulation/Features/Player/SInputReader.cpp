#include <cassert>
#include "SInputReader.h"
#include "Simulation/ECS/Features/Input/CQueuePlayerMoveDirections.h"
#include "Simulation/Features/Shooting/CCannon.h"
#include "Simulation/ECS/Entity.h"
#include "Simulation/Features/Shooting/CRequestFire.h"
#include "Simulation/ECS/Features/Input/CQueueMouseClicks.h"
#include "Simulation/ECS/Features/Input/CPlayerControllableTag.h"
#include "Simulation/ECS/Features/Movable/CPhysics.h"
#include "Utility/Math/Vectors/Vectors.h"

void handleMovingPlayer()
{
    auto queueOpt = CQueuePlayerMoveDirections::TryGetFirst();
    assert(queueOpt);

    if (queueOpt->value.empty())
    { return; }

    sf::Vector2f playerMoveDirection = queueOpt->value.front();
    for (auto& [player, physics]: CPhysics::All() | CPlayerControllableTag::Filter())
    {
        physics.appliedForces += norm(playerMoveDirection);
    }
}

void handleMovingMouse()
{

}

void handleMouseClick()
{
    auto clicksQueueOpt = CQueueMouseClicks::TryGetFirst();
    assert(clicksQueueOpt);
    assert(!CCannon::All().empty());

    if (clicksQueueOpt->value.empty())
    { return; }

    ECS::Entity* player = CCannon::All().begin()->first;
    player->Claim<CRequestFire>();
}

void SInputReader::Update(float)
{
    handleMovingPlayer();
    handleMovingMouse();
    handleMouseClick();
}
