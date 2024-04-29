#include "SInputApplier.h"
#include "CMouseClickQueue.h"
#include "CMovementDirectionQueue.h"
#include "CMousePosQueue.h"
#include "Simulation/Features/Shooting/CRequestFire.h"
#include "Simulation/Features/Shooting/CCannon.h"
#include "Simulation/ECS/Entity.h"
#include "Utility/Math/Vectors/Vectors.h"
#include "Simulation/ECS/BasicFeatures/Movable/CRequestMovement.h"

void SInputApplier::Update(float dt)
{


    auto& moveDirs = CMovementDirectionQueue::AllEntities().begin()->second;
    sf::Vector2f& playerMoveRequestDirection = CRequestMovement::AllEntities().begin()->second.direction;
    if(!moveDirs.queue.empty())
    {
        sf::Vector2f moveDir = moveDirs.queue.front();
        moveDirs.queue.pop();

        playerMoveRequestDirection = moveDir;
    }

    auto& mousePositions = CMousePosQueue::AllEntities().begin()->second;
    if(!mousePositions.queue.empty())
    {

    }

    auto& clicksPos = CMouseClickQueue::AllEntities().begin()->second;
    if(!clicksPos.queue.empty())
    {
        auto& [player, cannon] = *CCannon::AllEntities().begin();
        player->ClaimComponent<CRequestFire>();
        clicksPos.queue.pop();
    }
}
