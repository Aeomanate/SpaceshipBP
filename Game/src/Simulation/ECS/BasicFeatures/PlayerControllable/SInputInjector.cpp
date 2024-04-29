#include "SInputInjector.h"
#include "CMovementDirectionQueue.h"
#include "Simulation/ECS/Entity.h"
#include "CMouseClickQueue.h"
#include "CMousePosQueue.h"

void SInputInjector::Update(float dt)
{

}

void SInputInjector::InjectMovement(sf::Vector2f direction)
{
    auto& [_, acceleration] = *CMovementDirectionQueue::AllEntities().begin();
    acceleration.queue.push(direction);
}

void SInputInjector::InjectMouseClick(sf::Vector2f position)
{
    auto& [_, mouseClicks] = *CMouseClickQueue::AllEntities().begin();
    mouseClicks.queue.push(position);
}

void SInputInjector::InjectMousePosition(sf::Vector2f position)
{
    auto& [_, mousePositions] = *CMousePosQueue::AllEntities().begin();
    mousePositions.queue.push(position);
}
