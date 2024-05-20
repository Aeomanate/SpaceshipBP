#include "SInputReader.h"

#include <cassert>
#include "Core/Application/ObjectsAggregator/GetterConfig.h"
#include "Utility/Math/Vectors.h"
#include "Simulation/ECS/ECS.h"
#include "Simulation/Features/Shooting/CCannon.h"
#include "Simulation/Features/Shooting/CRequestFire.h"

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
    const auto& mousePosQueue = REF(CInputMousePositions::TryGetFirstDataPtr()).value;
    if(mousePosQueue.empty())
    { return; }

    float playerRotateAngle = 0;
    for (auto [player, _]: CPlayerControllableTag::All())
    {
        sf::Vector2f playerPos = player->Get<CPosition>();
        sf::Vector2f mousePos = mousePosQueue.front();

        const ConfigTexture& playerConfigTexture =
            getConfig().resources.textures.Find([] (const ConfigTexture& configTexture) {
                return configTexture.name == getConfig().simulation.player.imageName;
            });

        sf::Vector2i textureOrientation = playerConfigTexture.orientation;

        playerRotateAngle = angleDeg(sf::Vector2f(textureOrientation), mousePos - playerPos);

        player->Get<CRotation>().value = playerRotateAngle;
    }
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
