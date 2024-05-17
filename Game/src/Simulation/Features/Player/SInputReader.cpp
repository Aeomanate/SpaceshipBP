#include <cassert>
#include "SInputReader.h"
#include "Simulation/ECS/Features/Input/CInputMoveDirections.h"
#include "Simulation/Features/Shooting/CCannon.h"
#include "Simulation/ECS/Entity.h"
#include "Simulation/Features/Shooting/CRequestFire.h"
#include "Simulation/ECS/Features/Input/CInputMouseClicks.h"
#include "Simulation/ECS/Features/Input/CPlayerControllableTag.h"
#include "Simulation/ECS/Features/Movable/CPhysics.h"
#include "Utility/Math/Vectors.h"
#include "Core/Application/ObjectsAggregator/GetterConfig.h"

void handleMovingPlayer()
{
    auto& queue = REF(CInputMoveDirections::TryGetFirstDataPtr());
    if (queue->empty())
    { return; }

    sf::Vector2f playerMoveDirection = queue->front();
    for (auto& [player, physics]: CPhysics::All() | CPlayerControllableTag::Filter())
    {
        if(isSemiZero(playerMoveDirection))
        { continue; }

        physics.appliedForces +=
            norm(playerMoveDirection)
            * getConfig().simulation.player.enginePowerMultipler.CastTo<float>();
    }
}

void handleMovingMouse()
{

}

void handleMouseClick()
{
    if (REF(CInputMouseClicks::TryGetFirstDataPtr())->empty())
    { return; }

    assert(!CCannon::Empty());
    auto& [player, cannon] = *CCannon::All().begin();
    player->Claim<CRequestFire>();
}

void SInputReader::Update(float)
{
    handleMovingPlayer();
    handleMovingMouse();
    handleMouseClick();
}
